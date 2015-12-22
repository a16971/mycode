#include <iostream>

using namespace std;

int divide_2_int(int dividend, int divisor)
{
	unsigned long long divd = dividend, divs = divisor;
	int ret = 0;
	if(dividend < 0) divd = -divd;
	if(divisor < 0) divs = -divs;
	
	while(divd >= divs)
	{	
		int i = 0;
		int t = divs;
		for(; t <= divd; ++i)
			t <<= 1;

		ret += (1 << (i - 1));
		divd -= ( t >> 1);
	}

	return ((dividend < 0 ^  divisor < 0) ? -ret: ret);
}

int main(void)
{
	int a, b;
	while(1)
	{
		cout << "a = ";
		cin >> a;
		cout  << "b = ";
		cin >> b ;
		cout << endl;
		cout << divide_2_int(a,b) << endl;
	}
}
	 
