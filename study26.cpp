//tcp��socket�׽��ֱ���

//�����
int sur() {
	//���������׽���
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	
	//ip��ʼ��
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	inet_aton("192.168.204.200", &addr.sin_addr);//�ַ���ת��

	//��bind
	int r = bind(ldf, (struct sockaddr*)&addr, sizeof(addr));

	//���óɱ����׽���listen
	if ((r = listen(lfd, SOMAXCONN) == -1) {
		perror("listen"),exit(0);
	}//����Ϊ���óɹ�

	//�ȴ�����accept
	int newfd=accept(lfd,NULL,NULL);

}


//�ͻ���

int client() {
	//�����׽���
	int fd = socket(AF_INET, SOCK_STREAM, 0);

	//��ipi��Ϣ����
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	inet_aton("192.168.204.200", &addr.sin_addr);

	//����
	int r = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
}