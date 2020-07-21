// ∑÷¿Îœﬂ≥Ã


#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <sys/syscall.h> 

typedef struct { char* name; int id; }td_t;
__thread td_t g_data = { "", 0 };

void* r1(void* arg) {
	g_data.name = "thread1";
	g_data.id = syscall(SYS_gettid);
	printf("r1()1: name=%s,id=%d\n", g_data.name, g_data.id);
	sleep(2);
	printf("r1()2: name=%s,id=%d\n", g_data.name, g_data.id);
}

void* r2(void* arg) {
	sleep(1);
	g_data.name = "thread2";
	g_data.id = syscall(SYS_gettid);
	printf("r2()1: name=%s,id=%d\n", g_data.name, g_data.id);
}

int main(void) {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, r1, NULL);
	pthread_create(&t2, NULL, r2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}

