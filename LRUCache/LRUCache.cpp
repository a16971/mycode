#include <list>
#include <iostream>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

class LRUCache
{
	list<pair<int,int> > m_cache_list;
	unordered_map<int, list<pair<int,int> >::iterator> m_keypos_hash;
	int m_capacity;
public:
    LRUCache(int capacity):m_capacity(capacity) {
        
    }
    
    int get(int key) {
		unordered_map<int,list<pair<int,int> >::iterator>::iterator  hashmap_it;
		list<pair<int, int> >::iterator cache_it;
		pair<int,int> pair;
		int ret = -1;

		if( (hashmap_it = m_keypos_hash.find(key)) != m_keypos_hash.end() )
		{
			cache_it = m_keypos_hash[key];
			pair = *cache_it;
			m_cache_list.erase(cache_it);
			m_cache_list.push_front(pair);
			m_keypos_hash[key] = m_cache_list.begin();
			ret = pair.second;
		} 
		return ret;
    }

    void set(int key, int value) 
	{
		list<pair<int, int> >::iterator cache_it;
		unordered_map<int,list<pair<int,int> >::iterator>::iterator  hashmap_it;
		pair<int, int> pair(key, value);

		if( (hashmap_it = m_keypos_hash.find(key)) != m_keypos_hash.end() )
		{
			cache_it = m_keypos_hash[key];
			m_cache_list.erase(cache_it);
			m_cache_list.push_front(pair);
			m_keypos_hash[key] = m_cache_list.begin();
			
		}else
		{
			if(m_capacity == m_cache_list.size())
			{
				m_cache_list.pop_back();
			}
			m_cache_list.push_front(pair);
			m_keypos_hash[key] = m_cache_list.begin();
		}
	} 
	
	void print(void)
	{
		
		cout << "Cache capacity is: " << m_capacity << endl;
		cout << "Cache size is: " << m_cache_list.size() << endl;

		for( list<pair<int, int> >::iterator it = m_cache_list.begin(); it != m_cache_list.end(); ++it)
			cout << "<key, Value> is <" << (*it).first << ", " << (*it).second << ">\n";
	}
};

int main(void)
{
	LRUCache cache(20);
	int j = 1 << 30;

	cout << j << endl;

	for(int i = 1; i <= j; i++)
		cache.set(i, i);

	cache.set(6,600);
	cache.set(7,700);
	cache.print();	

	return 1;

}
