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
	sem_t _sem_item, _sem_space;	
public: 
	Buffer():_in(0), _out(0)
	{
		sem_init(&_sem_item, 0, 0);
		sem_init(&_sem_space, 0, BUF_SIZE);
	}

	~Buffer()
	{
		sem_destroy(&_sem_item);
		sem_destroy(&_sem_space);
	}

	void insert(T t)
	{
		sem_wait(&_sem_space);
		_buffer[_in] = t;
		_in = (_in + 1) % BUF_SIZE;
		sleep(0.1);
		cout << "produced: " << t << endl;
		sem_post(&_sem_item);
	}
	
	T remove()
	{
		T ret;
		sem_wait(&_sem_item);
		ret = _buffer[_out];
		_out = (_out + 1) % BUF_SIZE;
		sem_post(&_sem_space);
		return ret;
	}
};

Buffer<int> g_buffer;

void * producer(void * data)
{
	for(int i = 0; i < 200; ++i)
		g_buffer.insert(i);
}

void * consumer(void * data)
{
	while(1)
	{ 
		sleep(rand()%4);
		cout << "	consumed: " << g_buffer.remove() << endl;
	}	
}


int main(void)
{

	pthread_t tid_p, tid_c;

	pthread_create(&tid_p, NULL, producer,NULL);
	pthread_create(&tid_c, NULL, consumer,NULL);



	pthread_join(tid_p, NULL);
	pthread_join(tid_c, NULL);
	
	return 0;
}

	
		
