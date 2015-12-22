#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_TASK 100

#define THREDS_COUNT 3

sem_t sem1,sem2,sem3;

void * _thread1(void* data);
void * _thread2(void* data);
void * _thread3(void* data);

int main(int argc, char ** argv)
{
	pthread_t tid[THREDS_COUNT];

	sem_init(&sem1, 0, 0);
	sem_init(&sem2, 0, 0);
	sem_init(&sem3, 0, 0);

	pthread_create(&tid[0], NULL, _thread1, NULL);
	pthread_create(&tid[0], NULL, _thread2, NULL);
	pthread_create(&tid[2], NULL, _thread3, NULL);

	sem_post(&sem1);
	
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);

	sem_destroy(&sem1);
	sem_destroy(&sem2);
	sem_destroy(&sem3);
	
	return 0;
}

void * _thread1(void * data)
{
	int i = MAX_TASK;
	while(i)
	{
		sem_wait(&sem1);
		printf("%d \n", 1);
		sleep(0.5);
		sem_post(&sem2);
		i--;
	}
	return NULL;
}
void * _thread2(void * data)
{
	int i = MAX_TASK;
	while(i)
	{
		sem_wait(&sem2);
		printf("%d \n", 2);
		sleep(1);
		sem_post(&sem3);
		i--;
	}
	return NULL;
}
void * _thread3(void * data)
{
	int i = MAX_TASK;
	while(i)
	{
		sem_wait(&sem3);
		printf("%d \n", 3);
		sleep(1);
		sem_post(&sem1);
		i--;
	}
	return NULL;
}
