//线程间同步，信号量
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <semaphore.h> 

#define PRO 3 
#define COR 2 
#define BUFFSZ 5 
sem_t full_id;
sem_t empty_id;
pthread_t tid[PRO + COR];
pthread_mutex_t mutex;
int buf[BUFFSZ];
int in = 0;
int out = 0;
int ready = 1;

void* pro(void* arg) {
	int id = *(int*)arg;
	int i;
	while (1) {
		sem_wait(&full_id);
		pthread_mutex_lock(&mutex);
		printf("%d生产者线程开始生产:\n", id);
		buf[in] = ready++;
		int tmp = in;
		in = (in + 1) % BUFFSZ;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty_id);
		printf("%d生产者生产完毕%d产品,装在buf[%d]位置\n", id, ready - 1, tmp);
	}

	return arg;
}
void* cor(void* arg) {
	int id = *(int*)arg;
	int i = 0;
	while (1) {
		sem_wait(&empty_id);
		pthread_mutex_lock(&mutex);
		printf("%d 消费者线程:\n");
		for (i = 0; i < BUFFSZ; i++) {
			printf("\tbuf[%d]=%d", i, buf[i]);
			if (i == out) {
				printf("====> out");
			}
			printf("\n");
		}
		out = (out + 1) % BUFFSZ;
		pthread_mutex_unlock(&mutex);
		sem_post(&full_id);
	}

	return arg;
}
int main(void) {
	int i;

	pthread_mutex_init(&mutex, NULL);
	sem_init(&full_id, 0, BUFFSZ);
	sem_init(&empty_id, 0, 0);

	for (i = 0; i < PRO; i++) {
		int* p = malloc(sizeof(int));
		*p = i;
		pthread_create(&tid[i], NULL, pro, p);
	}
	for (i = 0; i < COR; i++) {
		int* p = malloc(sizeof(int));
		*p = i;
		pthread_create(&tid[PRO + i], NULL, cor, p);
	}

	for (i = 0; i < PRO + COR; i++) {
		int* p = NULL;
		pthread_join(tid[i], (void**)&p);
		free(p);
	}

	pthread_mutex_destroy(&mutex);
	sem_destroy(&full_id);
	sem_destroy(&empty_id);
}

