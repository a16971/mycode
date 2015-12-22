#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

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

int main(void)
{

	int a[] = {2, 3, 4, 11, 13, 9, 1, 0,5};
	vector<int> v  = {2, 3, 4, 11, 13, 9, 1, 0,5};
	int* b = twoSum(a, 9);
	
	cout << b[0] << " " << b[1] << endl;
	twoSum_1(v, 9);
	
	return 0;
}
