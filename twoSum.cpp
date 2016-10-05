#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <utility>

using namespace std;
using namespace std::tr1;
int*  twoSum(int  number[], int target)
{
	int*  ret= new int[100];
	int k = 0;
	size_t len = sizeof(number);
	cout << "size of array is: " << len << endl;

	for(int i = 0; i < len; i++)
		for( int j = i+1; j < len; j++)
			if(number[i] + number[j] == target)
			{	ret[k] = i;
				ret[k++] = j;
				k++;
			}
	return ret;
}


vector<int> twoSum_1(vector<int> &array, int target)
{
	vector<int> ret;

	unordered_map<int, int> lookup;

	for(int i = 0; i < array.size(); ++i)
		lookup[array[i]] = i;
	
	for(int i = 0; i < array.size(); ++i)
	{
		int key = target - array[i];
		if(lookup.count(key) && lookup[array[i]] != lookup[key])
		{
			ret.push_back(i+1);
			ret.push_back(lookup[key]+1);
		}

	}
	
	for( vector<int>::iterator  it = ret.begin(); it != ret.end(); ++it)
		cout << *it << endl;
}

pair<int,int> twoSum_2(int a[],int target)
{
	int* ret = new int[2];
	pair<int, int> ret_pair;
	unordered_map<int, int> hash_t;
	unordered_map<int, int>::iterator itr;

	for(int i = 0; i < sizeof(a); i++)
	{
		if((itr = hash_t.find(target - a[i])) != hash_t.end())
		{
			ret[0] = hash_t[target - a[i]];
			ret[1] = i;
			ret_pair = make_pair(hash_t[target - a[i]],i);	 
		}else
			hash_t[a[i]] = i;
	}
	return ret_pair;
}
int main(void)
{

	int a[] = {2, 3, 4, 11, 13, 9, 1, 0,5};
	//vector<int> v  = new vector<int>(a);//{2, 3, 4, 11, 13, 9, 1, 0,5};
	int* b = twoSum(a, 9);
	pair<int, int> p; 
	cout << b[0] << " " << b[1] << endl;
//	twoSum_1(v, 9);
	p  = twoSum_2(a, 14);	
	cout << b[0] << ":" << b[1] << endl;
	return 0;
}
