#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>
// ɨ�������ţ������Ǹ��ǿ���
#define PACK_LEN 72


void make_icmp_packet(struct icmp* picmp, int len, int n);
u_short checksum(u_short* data, int len);
void tvsub(struct timeval* out, struct timeval* in);


int main(void) {
	char buf[32] = "39.99.249";
	printf("����������Ҫɨ������Σ�xxx.xxx.xxx����");
	scanf("%s", buf);
	int i, j;
	char ip_addr[32];

	int sfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);//����ԭʼ�׽��֣�ר�Ž���icmp����
	//ԭʼ�׽��֣�����Ҫ�������֣���˺�udpһ����ֱ��ʹ��sendto
	if (sfd == -1)perror("socket"), exit(1);

	for (i = 1; i < 255; i++) {//��ping 0����Ϊ0�ǹ㲥�������Դ�1��ʼ
		memset(ip_addr, 0x00, 32);
		sprintf(ip_addr, "%s.%d", buf, i);//ƴ������ip��ַ��ǰ��������Σ��������������
		printf("����ɨ�裺%s\n", ip_addr);
		char send_buf[PACK_LEN];//���崫������
		struct sockaddr_in addr;
		memset(&addr, 0x00, sizeof(addr));
		addr.sin_family = AF_INET;
		inet_aton(ip_addr, &addr.sin_addr);//�������û�ж˿ںŵ�
		for (j = 0; j < 3; j++) {
			make_icmp_packet((struct icmp*)send_buf, PACK_LEN, j);//��װicmp����
			if (sendto(sfd, send_buf, PACK_LEN, 0, (struct sockaddr*) & addr, sizeof(addr)) == -1) {//����  ����Ҫ���͵�Ŀ���ַ����˴���addr
				perror("sendto"), exit(1);
			}
			fd_set rest;//df_set���͵�����
			FD_ZERO(&rest);
			FD_SET(sfd, &rest);
			struct timeval tv;///��ʱ�ṹ��
			tv.tv_sec = 0;
			tv.tv_usec = 200 * 1000;//���峬ʱ��ʱ��
			while (1) {
				int ready;
				if ((ready = select(sfd + 1, &rest, NULL, NULL, &tv)) <= 0) {//С�ڵ����㳬ʱ�����뿪���ѭ�������û�յ���������ѭ�����½��У��յ�֮���ٽ���recvfrom����
					break;//��select����ҪĿ����Ϊ�˳�ʱ
				}
				char recv_buf[2048];//�����ݵĿռ�
				if (recvfrom(sfd, recv_buf, 2048, 0, NULL, NULL) == -1)exit(0);//������  ���ָ�����Ǹ��ط������������򽫺����NULL�����޸ģ����ﲻ��Ҫ�򲻽��и�
				//��Ϊ����recvfrom����û�յ����߳�ʱ��������ǰ��ʹ��select
				struct ip* pip = (struct ip*)recv_buf;//  icmpȱʡͷ�����������ip ��tcp����������˻�ʹ��int op= 1;setsockopt(sfd,IPPROTO,ip_hdrincl,&op,sizeof(op));��ipͷ�����뵽�׽�������
				int len = pip->ip_hl << 2;//��ȡ�ײ����� �����ip����ײ�����ֻ�ܹ���1������0����hdlen���ĸ��ֽڣ�����ȡ����ip�ײ���С��Ҫ����4
				if (pip->ip_src.s_addr == addr.sin_addr.s_addr) {//�����˷������ǵ�Դip�����ǵ�Ŀ��ip��ȣ�����ڽ��д���������򲻽��д���
					struct icmp* picmp = (struct icmp*)(recv_buf + len);//ȡ��icmp���ģ�ָ������ƶ�ipͷ����С�ľ���
					if (picmp->icmp_type == ICMP_ECHOREPLY) {//�Է��յ������Ƿ��ص�Ӧ��ĺ� ��ICM_ECHOREPLY
						printf("\t%s   ", inet_ntoa(pip->ip_src));//�Է�������ip
						struct timeval curt;//����ʱ��
						gettimeofday(&curt, NULL);//��ȡ��ǰʱ��
						tvsub(&curt, (struct timeval*)(picmp->icmp_data));//����������ʱ�䣬���Ƿ��͵�ʱ��ͶԷ�������Ӧ���ʱ��
						printf("\tttl:%hhu rrt:%d\n", pip->ip_ttl, curt.tv_sec + curt.tv_usec / 1000);//������ʱ�����ӡ����
					}
					goto lab;//�ߵ�ip�����������ʾ�ɹ���������˲�����������Ҫֱ������������forѭ�� goto
				}
			}
		}
	lab:;//Ŀ����һ������䣬Ŀ�Ĳ���lab����
	}
}

void make_icmp_packet(struct icmp* picmp, int len, int n) { //��װicmp����
	memset(picmp, 0x00, len);
	gettimeofday((struct timeval*)(picmp->icmp_data), NULL);//��������װ���ǵ�ǰ��ʱ��
	picmp->icmp_type = ICMP_ECHO;//�������ͣ�����������ĺ� ICMP_ECHO��
	picmp->icmp_code = 0;//���
	picmp->icmp_cksum = 0;//����� ����պ���ʹ��У����㷨�����м���
	picmp->icmp_id = getpid();//��ʶ����Ҳ���ǵ�ǰ���̵Ľ���id
	picmp->icmp_seq = n;//���
	picmp->icmp_cksum = checksum((u_short*)picmp, len);//�㷨
}


u_short checksum(u_short* data, int len) {
	u_long sum = 0;

	for (; len > 1; len -= 2) {//�㷨����˼��:��16λΪ��λ������ӣ�֮��������
		sum += *data++;
		if (sum & 0x80000000) {//����Ĵ���ʽ
			sum = (sum & 0xffff) + (sum >> 16);
		}
	}

	if (len == 1) {//���ʣ��һ��
		u_short i = 0;
		*(u_char*)&i = *(u_char*)data;
		sum += i;
	}

	while (sum >> 16) {//��16λ�����1���������㣬��Ϊ����ֻ��Ҫ�͵�16λ
		sum = (sum & 0xffff) + (sum >> 16);
	}
	return (sum == 0xffff) ? sum : ~sum;
}

void tvsub(struct timeval* out, struct timeval* in) {
	out->tv_sec -= in->tv_sec;
}






