#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "threadpool.h"

void* myfun(void* arg) {
	int id = *(int*)arg;
	free(arg);
	printf("id=%d thread_id=%p 开始工作\n", id, pthread_self());
	sleep(5);
	printf("id=%d thread_id=%p 退出\n", id, pthread_self());
}

int main(void) {
	int i;
	threadpool_t pool;

	threadpool_init(&pool, 3);
	for (i = 0; i < 5; i++) {
		int* p = malloc(sizeof(int));
		*p = i;
		threadpool_add_task(&pool, myfun, p);
	}

	threadpool_destroy(&pool);
}

