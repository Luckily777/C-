//ɨ��˿ں�
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
//ɨ�赽������֮�󣬿�����Щ�˿��Ǵ򿪵ĺ���˼�룺(ȫ����)ֱ��ʹ��connet���ӣ��ܹ������ǿ��ģ��������ǹص�
int tcp_connet(char* ip, int i) {
	int sfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(i);//�������ֽ���ת��Ϊ�����ֽ��� �˿�
	inet_aton(ip, &addr.sin_addr);
	if (connect(sfd, (struct sockaddr*) & addr, sizeof(addr)) == -1) {
		return 0;//������ʧ�ܣ��򷵻�
	}
	else {
		close(sfd);//���ӳɹ������ɨ�赽�˿ڣ� �ر�sfd�׽���
	}
	return 1;
}

int main(void) {
	char ip[32] = {};
	int start_port;
	int end_port;
	printf("ip:");
	scanf("%s", ip);
	printf("start:");
	scanf("%d", &start_port);
	printf("end:");
	scanf("%d", &end_port);

	int i;
	for (i = start_port; i <= end_port; i++) {
		if (tcp_connet(ip, i) == 1) {//����1��ʾ�˿���ͨ��
			struct servent* ps = getservbyport(htons(i), "tcp");//ÿ���˿�����Ӧ�ķ��� ��getservbyport()��һ���˿���Ҫ�˿ڵ�tcp����udp���ͻ᷵������һ���ṹ��,����ṹ��֮�о������֣��������˿ں�
			printf("%d,%s", i, (ps == NULL) ? "unkown" : ps->s_name);//�Ѷ�Ӧ�Ķ˿ں����ִ�ӡ����
		}
	}
}

