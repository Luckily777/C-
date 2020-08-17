//dup套接字


//服务端
int sur() {
	int i;
	int sfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9898);
	inet_aton("192.168.204.200", &addr.sin_addr);

	int r = bind(sfd, (struct sockaddr*) & addr, sizeof(addr));
	if (r == -1)perror("bind"), exit(1);

	char buf[1024];
	struct sockaddr_in paddr;
	socklen_t len = sizeof(paddr);
	while (1) {
		memset(buf, 0x00, sizeof(buf));
		recvfrom(sfd, buf, 1024, 0, (struct sockaddr*) & paddr, &len);

		for ();

		sendto(sfd, buf, strlen(buf), 0, (struct sockarr*) & paddr, len);
	}
}


//客户端
int client() {
	int cfd = socket(AF_INET, SOCK_DGRAM, 0);
	char buf[1024] = {};

	struct sockaddr_in addr;
	socklen_t len = sizeof addr;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(9898);
	inet_aton("192.168.204.200", &addr.sin_addr);
	while (fegts(buf, 1024, stdin) != NULL) {
		sendto(cfd, buf, strlen(buf), 0, (struct sockarr*) & addr, len);
		memset(buf, 0x00, sizeof(buf));
		recvfrom(cfd, buf, 1024, 0, NULL, NULL);
	}
}