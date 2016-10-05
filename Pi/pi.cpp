#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector> 
#include <time.h>
using namespace std;

int main(void)
{
	int n = 100000000;
	int count = 0;
	double pi = 0;

	for(int i; i < n; ++i)
	{
	
		double x = ((double) rand() / (RAND_MAX));
		double y = ((double) rand() / (RAND_MAX));
		count += ( x * x + y * y) < 1 ? 1 : 0;
	}
	pi = (count * 4)  ; 
	cout << " count = " << count << endl;
	cout << " Pi = " << pi << endl;
	return 0;
}

