#include <iostream>
#include <string> 

using namespace std;

long long  fibonacci(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    long long fN = 0;
    long long fN_1 = 1;
    long long fN_2 = 0;
    for( int i = 2; i <= n; ++i)
    {
        fN = fN_1 + fN_2;
        fN_2 = fN_1;
        fN_1 = fN;
    }
    return fN;
}

long long fibonacci_recursive(int n)
{
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main(void)
{
	cout << "recursive fibonacci(50)" << fibonacci_recursive(50) << endl;
	return 1;
}

