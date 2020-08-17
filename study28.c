//select client

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
	int cfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9898);
	inet_aton("192.168.204.200", &addr.sin_addr);
	int r = connect(cfd, (struct sockarrd*) & addr, sizeof(addr));
	if (r == -1) perror("connect"), exit(1);

	int key_fd = fileno(stdin);
	int maxfd = cfd > key_fd ? cfd : key_fd;
	fd_set rest;
	FD_ZERO(&rest);

	char buf[1024] = {};
	for (;;) {
		FD_SET(cfd,&rest);
		FD_SET(key_fd,&rest);
		int ready = select(maxfd + 1, &rest, NULL, NULL, NULL);
		if (ready <= 0) {
			continue;
		}
		if (FD_ISSET(cfd, &rest)) {
			memset(buf, 0x00, sizeof(buf));
			int r = read(cfd, buf, 1024);
			if (r <= 0) {
				printf("server close\n");
				break;
			}
			printf("=> %s\n", buf);
		}
		if (FD_ISSET(key_fd, &rest)) {
			memset(buf, 0x00, sizeof(buf));
			if (fgets(buf, 1024, stdin) == NULL) {
				break;
			}
			write(cfd, buf, strlen(buf));
		}
	}
}