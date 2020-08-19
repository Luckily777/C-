//信号


void handler(int s) {
	printf("recv %d\n", s);
}

int main(void) {
	sigset_t set;
	signal(SIGINT, handler);
	sigeptyset(&set);
	sigaddset(&set, SIGINT);

	sigpocmask(SIG_BLOCK, &set, NULL);

	for (;;) {
		printf("xxxx\n");
		sleep(3);
		sigset_t pset;
		sigemptyset(&pset);
		sigpending(&pset);
		if (sigismember(&pest, SIGINT)) {
			sigset_t sset;
			sigemptyset(&sset);
			sigsuspend(&sset);
			break;
		}
	}
	sigprocmask(SIG_UNBLOCK, &set, NULL);

}


//管道输出重定向

int main(void) {
	int fds[2];
	pipe(fds);
	pid_t pid = fork();
	if (pid == 0) {
		close(fds[1]);
		dup2(fds[0], 0);
		execlp("wc", "wc", "-l", NULL);
		printf("hehe\n");
	}
	else {
		close(fds[0]);
		dup2(fds[1], 1);
		execlp("ls", "ls", "-l", NULL);
	}
}