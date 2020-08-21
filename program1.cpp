#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

enum { BEGIN, MYIFCONF, SCANHOST, SCANPORT, SHARK, DOS, QUIT, END };

struct proc_map {
	int id;
	char* proc_name;
}maps[] = {
	{BEGIN,NULL},
	{MYIFCONF,"./myifconfig"},
	{SCANHOST,"./scanhost"},
	{SCANPORT,"./scanport"},
	{SHARK,"./shark"},
	{DOS,"./dos"},
	{END,NULL}
};//���ܴ���

int menu() {
	int choose;
	do {
		system("clear");
		printf("\n\n\n\n\n");
		printf("\t\t\t###############################################\n");
		printf("\t\t\t# %d. myifconfig                               #\n", MYIFCONF);
		printf("\t\t\t# %d. scanhost                                 #\n", SCANHOST);
		printf("\t\t\t# %d. scanport                                 #\n", SCANPORT);
		printf("\t\t\t# %d. shark                                    #\n", SHARK);
		printf("\t\t\t# %d. dos                                      #\n", DOS);
		printf("\t\t\t# %d. quit                                     #\n", QUIT);
		printf("\t\t\t###############################################\n");

		printf("\t\t\t����������ѡ�� > ");
		scanf("%d%*c", &choose);
		if (choose <= BEGIN || choose >= END) {//��Խ�磬������Ҫô��������,Ҫô�˳�
			printf("�˵�ѡ����������Ƿ��������룿[y/n]:");
			char c;//�����Ƿ�ͬ�����������ѡ��
			scanf("%c", &c);
			if (c == 'Y' || c == 'y') {//��Ϊy��Y�Ļ���������ѭ����������
				continue;
			}
			exit(0);//��Ϊn�������Ļ�����ֱ�ӽ����뿪
		}
		else {//����Խ��֮���������������룬����do��whileѡ�� 
			break;
		}
	} while (1);

	return choose;//�����û��������ѡ��
}

void do_quit() {
	printf("ллʹ�ã�\n");
	exit(0);
}

void do_proc(int id) {
	int i;
	for (i = BEGIN; i < END; i++) {
		if (id == i) {
			if (fork() == 0) {
				sigset_t set;//����set�źż�
				sigemptyset(&set);//���set�źż�
				sigaddset(&set, SIGINT);//��SIGINT��ctrl + c���źŸ���set�źţ�����λ��Ϊ1
				sigprocmask(SIG_UNBLOCK, &set, NULL);//���SIGINT�źŵ�����

				execlp(maps[i].proc_name, maps[i].proc_name, NULL);//����ָ��Ŀ¼֮��ִ�и��ļ�
				//��ʹ��exec����Ϊ���ʹ��exec�Ὣ��ǰ���̸��滻������û�а취���������ˣ�����ʹ��execlp
				perror("execlp");//��ִ�д����򱨴�
				exit(0);//�ӽ���ִ��exec������
			}
			else {
				wait(NULL);//��������������ţ����ӽ���û�н���֮ǰ�����Լ���ֱ���ӽ��̽�����Ϊ��ʬ�ӽ���
			}
		}
	}
}


int main(void) {
	sigset_t set;//�źż���ʼ��
	sigemptyset(&set);//����źż�
	sigaddset(&set, SIGINT);//��SIGINT�źż��뵽set�źż�֮��
	sigprocmask(SIG_BLOCK, &set, NULL);//�ı�set�źŴ�����״̬��ʹ�ö���SIGINT�ź�
	//ʹ���ź���������Ϊ��ץ��ʱֻ��crtl+c���Խ�����������ʱ���ӽ��̶��յ��ź��ˣ����ֻ��Ҫ�ڸ������������ε�SIGINT�źţ����ӽ���Ҫ�յ�SIGINT�ź�

	while (1) {//���й���ѡ��
		int choose = menu();
		switch (choose) {
		case QUIT://��ѡ���˳�
			do_quit();
			break;
		default:
			do_proc(choose);//����ʵ��
			break;
		}
	}
}

