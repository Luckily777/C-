//sur select


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
	setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &op, sizeof(op));

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9898);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int r = bind(lfd, (struct sockaddr*) & addr, sizeof(addr));
	if (r == -1) perror("bind"), exit(1);

	listen(lfd, 10);
	return lfd;
}


int main() {
	int lfd = tcp_init();
	int clients[FD_SETSIZE];
	fd_set rest, allset;
	int maxfd,i;
	if (i = 0; i < FD_SETSIZE; i++) {
		clients[i] = -1;
	}

	FD_ZERO(&rest);
	FD_ZERO(&allset);

	FD_Set(lfd, &allset);
	maxfd = lfd;
	int maxi = -1;
	for (;;) {
		rest = allset;
		int nready = select(maxfd + 1, &rest, NULL, NULL, NULL);
		if (nready <= 0) {
			continue;
		}

	}
}