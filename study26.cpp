//tcp的socket套接字编码

//服务端
int sur() {
	//创建监听套接字
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	
	//ip初始化
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	inet_aton("192.168.204.200", &addr.sin_addr);//字符串转整

	//绑定bind
	int r = bind(ldf, (struct sockaddr*)&addr, sizeof(addr));

	//设置成被动套接字listen
	if ((r = listen(lfd, SOMAXCONN) == -1) {
		perror("listen"),exit(0);
	}//否则为设置成功

	//等待连接accept
	int newfd=accept(lfd,NULL,NULL);

}


//客户端

int client() {
	//创建套接字
	int fd = socket(AF_INET, SOCK_STREAM, 0);

	//将ipi信息放入
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	inet_aton("192.168.204.200", &addr.sin_addr);

	//连接
	int r = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
}