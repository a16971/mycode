#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

#define  BUF_SIZE  10
template <typename  T>
class Buffer
{
private:
	int _in;
	int _out;
	T _buffer[BUF_SIZE];
	sem_t _sem_item, _sem_space,_sem_guard;	
public: 
	Buffer():_in(0), _out(0)
	{
		sem_init(&_sem_item, 0, 0);
		sem_init(&_sem_space, 0, BUF_SIZE);
		sem_init(&_sem_guard, 0, 1);
	}

	~Buffer()
	{
		sem_destroy(&_sem_item);
		sem_destroy(&_sem_space);
		sem_destroy(&_sem_guard);
	}

	void insert(T t)
	{
		sem_wait(&_sem_space);
		sem_wait(&_sem_guard);
		_buffer[_in] = t;
		_in = (_in + 1) % BUF_SIZE;
		sleep(0.1);
		cout << "produced: " << t << endl;
		sem_post(&_sem_item);
		sem_post(&_sem_guard);
	}
	
	T remove()
	{
		T ret;
		sem_wait(&_sem_item);
		ret = _buffer[_out];
		_out = (_out + 1) % BUF_SIZE;
		cout << "		consumed: " << ret << endl;
		sem_post(&_sem_space);
		return ret;
	}
	bool isEmpty()
	{
		return(_in == _out);
	}
};

Buffer<int> g_buffer;

void * producer1(void * data)
{
	for(int i = 0; i < 20; i+=2)
	{
		g_buffer.insert(i);
//		cout << "thread 1 produced: " << i << endl;
	}
}

void * producer2(void * data)
{
	for(int i = 1; i < 20; i+=2)
	{	g_buffer.insert(i);
//		cout << "thread 2 produced: " << i << endl;
	}
}
void * consumer(void * data)
{
	while(1)
	{ 
	//	sleep(rand()%4);
		sleep(1);
		 g_buffer.remove(); 
	}	
}


int main(void)
{

	pthread_t tid_p1, tid_p2, tid_c;

	pthread_create(&tid_p1, NULL, producer1,NULL);
	pthread_create(&tid_p2, NULL, producer2,NULL);
	pthread_create(&tid_c, NULL, consumer,NULL);



	pthread_join(tid_p1, NULL);
	pthread_join(tid_p2, NULL);
	pthread_join(tid_c, NULL);
	
	return 0;
}

	
		
