第七节课的项目代码

1. 输出printf
int main(void) {
	int num;
	do {
		printf("请输入：");
		if (scanf("%d", &num) != 1) {
			printf("输入非法\n");
			scanf("%d[^\n]%*c");
			continue;
		}
		break;
	} while (1);
	printf("你充值%d\n", num);
}


2. 输入Scanf
int main() {
	int num;
	do {
		printf("请输入：");
		if (scanf("%d", &num) != 1) {
			printf("输入非法\n");
			scanf("%d*[^\n]%*c");
			continue;
		}
		break;
	} while (1);
	printf("你充值了多少%d\n",num);
}

3. 打印得缓存进度
ude <unistd.h>
#include <stdlib.h>

int main(void) {
	char* p = malloc(sizeof(char) * 10);
	setvbuf(stdout, p, _IONBF, 10);
	printf("this is maomaochong");
	//fflush(stdout);
	sleep(3);
}

4. 打印进度条**
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	char buf[100] = { '#' };
	char* p = "|/-\\";
	int i;
	for (i = 0; i < 100; i++) {
		buf[i] = '#';
		printf("[% -100s][%d%%][%c]\r", buf, i + 1, p[i % 4]);
		fflush(stdout);
		usleep(500000);
	}
}

