//myifconfig

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//ifconfig ��ȡ������һЩ��Ϣ

int main(void) {
	struct ifreq ir[5];//װ�豸������ ���ҿ���װ5��
	struct ifconf conf;//װ�����豸���嵥
	conf.ifc_len = sizeof(ir);//����Ĵ�С�������ǿ�ʼ����
	conf.ifc_req = ir;//�ѻ���ŵ�ifconf��buf��

	int sfd = socket(AF_INET, SOCK_STREAM, 0);//����������
	ioctl(sfd, SIOCGIFCONF, &conf);//��ȡ���ӿڵ��б�װ�뵽conf��
	int cnt = conf.ifc_len / sizeof(struct ifreq);//ʵ�ʻ���Ĵ�С�ж�󣬾���ʵ�ʵĳ���irһ���Ĵ�С
	printf("cnt =%d\n", cnt);//��ӡʵ���豸����
	int i;
	for (i = 0; i < cnt; i++) {
		printf("%s\n", ir[i].ifr_name);//��ӡ�豸������
		struct ifreq iq;
		memcpy(iq.ifr_name, ir[i].ifr_name, sizeof(ir[i].ifr_name));//Ҫ��ȡip��Ҫ�����豸����ȥ���ң��������ǽ���ǰ�豸���ֿ�����iq�ṹ���name�м���
		ioctl(sfd, SIOCGIFDSTADDR, &iq);//��ȡip��ַ
		struct sockaddr_in* addr = (struct sockaddr_in*) & iq.ifr_dstaddr;//����Ϊ�����ĵ�ַ��Ϣ��struct sockaddr���ͣ����������Ҫ��������һ�����ͽ���������
		printf("\tip :%s\t", inet_ntoa(addr->sin_addr));//��ӡ��ȡ����ip��ַ

		ioctl(sfd, SIOCGIFNETMASK, &iq);//��ȡ�������� ͨ����ͬ�Ĳ�����ȡ������Ϣװ����ͬ����������
		addr = (struct sockaddr_in*) & iq.ifr_netmask;//����������Ҳ����ȥ
		printf("\tnetmask :%s\t", inet_ntoa(addr->sin_addr));//��ӡ��������

		int ret = ioctl(sfd, SIOCGIFBRDADDR, &iq);//��ȡ�㲥��ַ
		addr = (struct sockaddr_in*) & iq.ifr_netmask;//�ѹ㲥��ַҲ����ȥ
		printf("\tbrdcast :%s\n", inet_ntoa(addr->sin_addr));//��ӡ�㲥��ַ

		ioctl(sfd, 0x8921, &iq);//��ȡMTU
		printf("\tMTU :%d\n", iq.ifr_mtu);//mtu����ip��ַ������Ҫת��ֱ�Ӵ�ӡ����

		ioctl(sfd, SIOCGIFHWADDR, &iq);//��ȡMAC��ַ
		char buf[6];
		memcpy(buf, iq.ifr_hwaddr.sa_data, 6);//�������������������buf֮��
		printf("\tHDaddr : %02X:%02X:%02X:%02X:%02X:%02X\n\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);//��ӡbufҲ����mac�ĵ�ַ
	}
	printf("�������������...\n");
	getchar();
}

