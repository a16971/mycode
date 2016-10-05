#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define TABLE_SIZE 1000

class hashmap
{
protected: 
	
	
	class node
	{
	private: 
		string	m_key;
		node*	m_next;
	public:
		node()
		{}

		node(string key, node* next):m_key(key),m_next(next)
		{}

		string getKey()const
		{
			return m_key;
		}
	
		node* getNext()const
		{
			return m_next;
		}

		void setNext(node* _node)
		{
			m_next = _node;
		}
	}; 
private:	
	node* m_table[TABLE_SIZE];
	
	int hash(string key)
	{
		long long sum = 0; 
		for(int i = 0; i < key.size(); ++i)
		{
		 	sum += key[i]*key[i];
			std::cout << "key[" << i << "]" <<  key[i] << endl;
		}
		cout << "log: hash of \"" << key << "\" is " << sum%TABLE_SIZE << endl;		
		return sum % TABLE_SIZE;
	}
	


public:

	hashmap()
	{
		for(int i = 0; i < TABLE_SIZE; ++i)
			m_table[i] = NULL;
	}

	~hashmap()
	{
		//mem leak here
	}

	int insertKey(string key)
	{
		int index = hash(key);
		node* newNode = new node(key, NULL);
		if(m_table[index] == NULL)
		{
			m_table[index] = newNode;
		}else
		{
			node* i_node = m_table[index]->getNext();
			while( i_node != NULL && i_node->getKey() != key) 
				i_node = i_node->getNext();

			if(i_node->getNext() == NULL)
				i_node->setNext(newNode);
			else
				index = -1;
		}
		
		return index;
	}

	int deleteKey(string key)
	{

	}

	int searchKey(string key)
	{
	}

	

};	


int main(void)
{

	hashmap  hmap;
	string s("abcdfdafdsafewqrewrwerqwr");
	string s1(s);
	cout << hmap.insertKey(s) << endl;
	cout << hmap.insertKey(s1) << endl;
	return 0;
}

