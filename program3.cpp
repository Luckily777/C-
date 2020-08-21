#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>//��ַת��
#include <sys/socket.h>//socket���
#include <netinet/in.h>
#include <linux/ip.h>//ipͷ��
#include <linux/if_arp.h>//arpͷ��
#include <linux/tcp.h>//tcpͷ��
#include <linux/udp.h>//udpͷ��
#include <linux/icmp.h>//icmpͷ��
#include <linux/if_ether.h>//��̫��arp���ݽṹ

void print_mac(struct ethhdr* p);
void parse_ip(char* buf);
void parse_arp(char* buf);

int main(void) {
	int sfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));//�׽��ֱ��
	//AF_PACKET ����·��   ֱ�����������������ͺͽ��ձ��ģ����������SOCKET�����ı���ֱ���͵���̫�����ӿڣ������յ����κα��Ľ�ֱ���͵�Ӧ�ó���
	//SOCK_RAW ԭʼ�׽��ֱ��
	//ETH_P_ALLץ��·��İ�����������·��ͷ������Ҫ������̫����ͷ�������еĶ�Ҫ
	char buf[2000];//1500 +ͷ��14 +β��4 
	while (1) {
		memset(buf, 0x00, sizeof(buf));
		int r = read(sfd, buf, 2000);//��buf�ж�ȡ����
		if (r <= 0) {//����ȡ����С�ڵ����㣬���ȡʧ��
			break;
		}
		struct ethhdr* peth = (struct ethhdr*)buf;//��̫����ͷ��
		print_mac(peth);//��ӡmac
		printf("Type: %#x\n", ntohs(peth->h_proto));//��̫���ϲ�Э������0800����0806

		//ʹ��ntohs�ǽ������ֽ���ת��Ϊ�����ֽ��������бȽ�
		if (ntohs(peth->h_proto) == ETH_P_IP) {//����ͷ��ΪIP  
			parse_ip(buf + sizeof(struct ethhdr));//ƫ�Ƶ���·���֡ͷ
		}
		else if (ntohs(peth->h_proto) == ETH_P_ARP) {//����ΪARP�㲥��
			parse_arp(buf + sizeof(struct ethhdr));//���˵���·���֡ͷ  
		}
	}
}

//��ӡmac
void print_mac(struct ethhdr* p) {
	printf("%02x:%02x:%02x:%02x:%02x:%02x", p->h_source[0], p->h_source[1], p->h_source[2], p->h_source[3], p->h_source[4], p->h_source[5]);//Դmac��ַ
	printf("<==>  %02x:%02x:%02x:%02x:%02x:%02x \n", p->h_dest[0], p->h_dest[1], p->h_dest[2], p->h_dest[3], p->h_dest[4], p->h_dest[5]);//Ŀ��mac��ַ
}

//��ӡudp
void print_udp(char* buf) {
	struct udphdr* pt = (struct udphdr*)buf;
	printf("%hu : %hu", ntohs(pt->source), ntohs(pt->dest));
	printf("\n\n");
}

//��ӡicmp
void print_icmp(char* buf) {
	struct icmphdr* imp = (struct icmphdr*)buf;
	printf("icmp");
	//��������Ҫ���������жϣ������ﲻ�� 
	//������Ļ�����Ҫ����ͷ�������ͺ�codeȡ������֮���ж�ʹ��������֮�е��Ǹ��ṹ��
	//printf("%hu   :  seq:%hu\n",imp->echo->id,imp->echo->sequence);
}

void print_tcp(char* buf) {
	struct tcphdr* pt = (struct tcphdr*)buf;
	printf("source:%hu:dest: %hu seq :%u", ntohs(pt->source), ntohs(pt->dest), ntohl(pt->seq));//Դ�˿ڣ�Ŀ��˿� �����к�

	if (pt->ack) {
		printf("\tack_seq : %u", ntohl(pt->ack_seq));//ackΪ1�Ż���Ӧ���
	}
	if (pt->fin) {//���ڼ���ӡ
		printf("\tfin");
	}
	if (pt->syn) {
		printf("\tsyn");
	}
	if (pt->ack) {
		printf("\tack");
	}

	printf("\n\n");
}

void parse_ip(char* buf) {
	struct iphdr* phdr = (struct iphdr*)buf;
	struct in_addr ad;//in_addr �ṹ����ֻ��s_addr װip
	ad.s_addr = phdr->saddr;//Դ��ַ
	printf("\t%s <==> ", inet_ntoa(ad));//��ipת��Ϊ�ַ���
	ad.s_addr = phdr->daddr;//Ŀ���ַ
	printf("%s, protocol : %hhd, tll :%hhu ,tot_len:%hu", inet_ntoa(ad), phdr->protocol, phdr->ttl, phdr->tot_len);//prorocol��λЭ�飬ttl����ʱ��tot_len16λ�ܳ���
	if (phdr->protocol == IPPROTO_TCP) {
		printf("\n\t\t");
		print_tcp(buf + sizeof(struct iphdr));
	}
	else if (phdr->protocol == IPPROTO_UDP) {
		printf("\n\t\t");
		print_udp(buf + sizeof(struct iphdr));
	}
	else if (phdr->protocol == IPPROTO_ICMP) {
		printf("\n\t\t");
		print_icmp(buf + sizeof(struct iphdr));
	}
}

void parse_arp(char* buf) {
	struct arphdr* phdr = (struct arphdr*)buf;
	printf("_be16:\t%x", phdr->ar_hrd);//��ӡӲ����ַ
}





