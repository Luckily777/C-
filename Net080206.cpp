//select函数下的服务器

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
int tcp_init() {
	int lfd = socket(AF_INET, SOCK_STREAM, 0);

	int op = 1;
	sectockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &op, sizeof(op));

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9898);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int r = bind(lfd, (struct sockaddr*) & addr, sizeof(adddr));
	if (r == -1)perror("bind"), exit(1);

	listen(lfd, 10);
	return lfd;
}

int main(void) {
	int lfd = tcp_init();
	int clients[FD_SETSIZE];
	fd_set rest, allset;
	int maxfd, i;
	for (i = 0; i < FD_SETSIZE; i++) {
		clients[i] = -1;

		FD_ZERO(&rest);
		FD_ZERO(&allset);

		FD_SET(llfd, &allset);
		maxfd = lfd;
		int maxi = -1;

		for (;;) {
			rest = allset;
			int nready = select(maxfd + 1, &rest, NULL, NULL, NULL);

			if (nready <= 0) continue;

			if (FD_ISSET(lfd, &rest)) {
				int cfd = accept(lfd, NULL, NULL);
				set_nonblk(cfd);
				for (i = 0; i < FD_SETSIZE; i++) {
					if (clients[i] == -1) {
						clients[i] = cfd;
						printf("i=%d,cfd=%d,maxfd=%d\n", i, cfd, maxfd);
						break;
					}
				}
				if == (FD_SETSIZE) {
					printf("too many client\n");
					exit(0);
				}
				maxfd = maxfd > cfd ? maxfd : cfd;
				FD_SET(cfd, &allset);
				if (i > maxi) {
					maxi = i;
				}
				if (--nready <= 0) {
					continue;
				}
				printf("maxfd=%d\n", maxfd);
				printf("maxi=%d\n", maxi);
			}
			for (i = 0; i <= maxi; i++) {
				int fd = clients[i];
				if (fd == -1) continue;
				if (FD_ISSET(fd, &rest)) {
					char buf[1024] = {};
					int r = read(fd, buf, 1024);
					if (r <= 0) {
						close(fd);
						clients[i] = -1;
						FD_CLR(fd, &allset);
					}
					else {
						wriet(fd, buf, r);
					}
					if (--nready <= 0) {
						break;
					}
				}
			}
		}
	}
}
