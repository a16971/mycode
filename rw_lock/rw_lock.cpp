#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <string> 
#include <atomic>
using namespace std;

string g_buffer( "abc"); 
class rw_lock 
{
	std::condition_variable cv_r;
	std::condition_variable cv_w;
	mutex	rm;
	mutex	wm;
	atomic<int> rCount;
	atomic<int> wCount;
public:
	rw_lock()
	{
		rCount = 0; 
		wCount = 0;
	};
	
	void read_lock()
	{
		{
			std::unique_lock<std::mutex> lock(rm);
			cv_r.wait(lock, [this]{return (wCount == 0); });
		}
		++rCount;
	};

	void read_unlock()
	{
		--rCount;
		cv_r.notify_one();
	};

	void write_lock()
	{
		std::unique_lock<std::mutex> lock(wm);
		cv_w.wait(lock,[this]{return(wCount == 0 && rCount == 0);});
		++wCount;
	};
	
	void write_unlock()
	{
		--wCount;
		cv_r.notify_all();
		cv_w.notify_one();
	}
	int reader()
	{
		return rCount;
	}
	int writter()
	{
		return wCount;
	}
};
rw_lock g_lock;

void read_thread(int i)
{
	g_lock.read_lock();
	while(1)
	{
		sleep(2);
		cout << "thread " << i << "rCount:" << g_lock.reader() << endl;
	}
}
void writer_thread()
{
	g_lock.write_lock();
	while(1)
	{
		g_buffer += " wCount:";
		g_buffer += g_lock.writter();
			
	}	
}


int main()
{
	std::thread reader1(read_thread,1);	
	sleep(1);
	std::thread reader2(read_thread,2);
	std::thread writter1(writer_thread);
	sleep(10);
	g_lock.read_unlock();
	g_lock.read_unlock();
	reader1.join();	
	reader2.join();
	writter1.join();
	return 1;

}
