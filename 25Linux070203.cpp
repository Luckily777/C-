#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include "threadpool.h"

void threadpool_init(threadpool_t* pool, int max_thread) {
	pthread_cond_init(&pool->cond, NULL);
	pthread_mutex_init(&pool->mutex, NULL);
	pool->first = NULL;
	pool->last = NULL;
	pool->counter = 0;
	pool->idle = 0;
	pool->max_thread = max_thread;
	pool->quit = 0;
}

void* routine(void* arg) {
	threadpool_t* pool = (threadpool_t*)arg;
	int timeout = 0;
	printf("%p thread created\n", pthread_self());
	while (1) {
		timeout = 0;
		pthread_mutex_lock(&pool->mutex);
		pool->idle++; //  刚开始，是一个空闲线程
		while (pool->first == NULL && pool->quit == 0) {
			struct timespec  abstime;
			clock_gettime(CLOCK_REALTIME, &abstime);
			abstime.tv_sec += 5;
			int ret = pthread_cond_timedwait(&pool->cond, &pool->mutex, &abstime);
			if (ret == ETIMEDOUT) {
				timeout = 1;
				printf("%p thread timeout\n", pthread_self());
				break;
			}
		}
		pool->idle--; // 得到任务，就不是一个空闲线程

		if (pool->first != NULL) { // 有任务，执行任务回调函数
			task_t* tmp = pool->first; // 取出任务队列队头节点
			pool->first = tmp->next;
			pthread_mutex_unlock(&pool->mutex);
			tmp->run(tmp->arg);
			free(tmp);
			pthread_mutex_lock(&pool->mutex);
		}

		if (pool->first == NULL && timeout == 1) {
			pool->counter--;
			pthread_mutex_unlock(&pool->mutex);
			break;
		}

		if (pool->first == NULL && pool->quit == 1) {
			pool->counter--;
			if (pool->counter == 0) { //  最后一个退出的线程，通知threadpool_destroy中的pthread_cond_wait
				pthread_cond_signal(&pool->cond);
			}
			pthread_mutex_unlock(&pool->mutex);
			break;
		}

		pthread_mutex_unlock(&pool->mutex);
	}

	printf("%p thread exit\n", pthread_self());
}

void threadpool_add_task(threadpool_t* pool, void* (*run)(void*), void* arg) {
	task_t* new_task = malloc(sizeof(task_t)); // 创建新的任务节点
	new_task->run = run;
	new_task->arg = arg;

	// 往任务队列中添加任务
	pthread_mutex_lock(&pool->mutex);
	if (pool->first == NULL) {
		pool->first = new_task;
	}
	else {
		pool->last->next = new_task;
	}
	pool->last = new_task;

	// 如果有空闲线程，直接唤醒空闲线程，执行当前任务
	if (pool->idle > 0) {
		pthread_cond_signal(&pool->cond);
	}
	else if (pool->counter < pool->max_thread) {
		// 如果没有空闲线程可以用来执行当前任务，并且没有达到上限，创建新线程
		pthread_t tid;
		pthread_create(&tid, NULL, routine, pool);
		pool->counter++;
	}
	pthread_mutex_unlock(&pool->mutex);
}

void threadpool_destroy(threadpool_t* pool) {
	if (pool->quit == 1)
		return;

	pthread_mutex_lock(&pool->mutex);
	pool->quit = 1;
	printf("我要杀了线程池\n");
	if (pool->counter > 0) {
		//  当线程池中空闲线程个数大于0时，
		//  pthread_cond_broadcast唤醒所有阻塞在pthread_cond_timedwait上的线程
		if (pool->idle > 0)
			pthread_cond_broadcast(&pool->cond);
		// 如果销毁线程池时，线程池中的线程正在执行任务
		// 不会收到broadcast的通知
		while (pool->counter > 0)
			pthread_cond_wait(&pool->cond, &pool->mutex);
	}
	pthread_mutex_unlock(&pool->mutex);

	pthread_cond_destroy(&pool->cond);
	pthread_mutex_destroy(&pool->mutex);
}