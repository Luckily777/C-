//聊天窗口的服务端
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct client {
	int cfd;
	char nickname[32];
}client_t;

typedef struct node {
	client_t c;
	struct node* next;
	struct node* prev;
}node_t;

node_t* head = NULL;

void list_init(void) {
	node_t* p = malloc(sizeof(node_t));

	p->next = p->prev = p;

	head = p;
}

void list_insert(client_t* pc) {
	node_t* p = malloc(sizeof(node_t));
	p->c = *pc;
	p->next = head->next;
	p->prev = head;
	head->next->prev = p;
	head->next = p;
}

void list_erase(int cfd) {
	node_t* p = head->next;

	while (p != head) {
		if (p->c.cfd == cfd) {
			p->next->prev = p->prev;
			p->prev->next = p->next;
			free(p);
			break;
		}
		p = p->next;
	}
}

int list_len() {
	node_t* p = head->next;
	int i = 0;
	while (p != head) {
		i++;
		p = p->next;
	}
}

void send_all(char* msg) {
	node_t* p = head->next;

	while (p != head) {
		write(p->c.cfd, msg, strlen(msg));
		p = p->next;
	}
}

int tcp_init() {
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	int op = 1;
	setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &op, sizeof(op));
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	add.sin_port = htons(9898);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int r = bind(lfd, (struct sockaddr*) & addr, sizeof(addr));
	if (r == -1) perror("bind"), exit(1);

	listen(lfd, SOMAXCONN);

	return lfd;
}

void* process(void* args) {
	int cfd = *(int*)args;
	free(args);

	char buf[1024];
	sprintf(buf, "欢迎来到聊天室\n");
	write(cfd, buf, strlen(buf));
	sprintf(buf, "昵称:");
	write(cfd, buf, strlen(buf));
	char nickname[100] = {};
	read(cfd, nickname, 100);
	nickname[strlen(nickname) - 1] = 0;

	memset(buf, 0x00, sizeof(buf));
	sprintf(buf, "%s上线了\n", nickname);
	printf("%s", buf);
	fflush(stdout);
	send_all(buf);

	client_t cli;
	cli.cfd = cfd;
	memset(buf, 0x00, sizeof(buf));
	sprintf(cli.nickname, "%s", nickname);
	list_insert(&cli);

	while (1) {
		memset(buf, 0x00, sizeof(buf));
		int r = read(cfd, buf, 1024);
		if (r <= 0) {
			sprintf(buf, "%s 下线了\n", cli.nickname);
			send_all(buf);
			break;
		}
		else {
			send_all(buf);
		}
	}
	list_erase(cfd);
	close(cfd);
}

int main(void) {
	list_init();
	int lfd = tcp_init();

	for (;;) {
		int cfd = accept(lfd, NULL, NULL);
		if (cfd <= 0) continue;
		pthread_t tid;
		int* p = malloc(sizeof(int));
		*p = cfd;
		pthread_create(&tid, NULL, process, p);
		pthread_detach(tid);
	}
}
