#include <math.h>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;


void removeDup(char* str)
{
	if (str == NULL) return; 
	int len = strlen(str);
	if (len < 2) return; 

	int tail = 1;
	
	int i = 1;
	for (i = 1; i < len; ++i)
	{
		int j;
		for (j = 0; j < tail; ++j)
		{
			if (str[i] == str[j]) break;
		}
		if (j == tail)
		{
			str[tail] = str[i];
			++tail;
		}
	
	}
	str[tail]=0;
}

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

void printCombination(char * sN, char* c)
{
	int sLen = strlen(sN);

	for(int  i = 0; i < sLen; ++i)
	{
		if( i == 0) 
			printf("%s%s\n",c,sN);
		else if( i == sLen - 1) 
			printf("%s%s\n",sN,c);
		else
		{
			char c_temp = sN[i];
			sN[i]= '\0'; 
			printf("%s%s%s\n",sN,c,sN + i+1);
			sN[i] = c_temp;
		}
	}
}


int char2digit(char c)
{
	if ( c >= '0' && c <= '9') return c - '0';
	else if ( c >= 'a' && c <= 'f') return 10 + c - 'a';
	else if ( c >= 'A' && c <= 'F') return 10 + c - 'A';
	return -1;
}

int digit2base(const char * digit, int base)
{
	if( digit == NULL || base < 2 || base > 16) return -1;

	int value = 0; 
	for( int i = strlen(digit) - 1; i >= 0; --i)
	{
		if(char2digit(digit[i]) < 0 || char2digit(digit[i])> base - 1) return -2;
		int power = strlen(digit) - i - 1;
		value += char2digit(digit[i]) * pow(base, power);
		cout << value << ":" << char2digit(digit[i]) << ":" << digit[i] << endl;
	}
	
	return value;
}
	
/*			
void permutation(char* input)
{
	if(input == null || strlen(input) == 0) return;

	char first[1];
	first[0] = input[0];

	for( int i = 0; i < strlen(input); ++i)
	{
*/		
		 
int  main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	string input;
	int n = 0; 
	char sN[]="abcdefg";
	char c[]="x";
	
	printCombination(sN,c);

	while(1)
	{	
//		cout << "input your string:" << endl;
//		cin >>  input;	
		//cout << input << endl;
//		removeDup((char*)input.c_str());	
//		cout << "output:" << endl << input << endl;
//		printf("output: %s \n", input.c_str());
		//cout << "input your N:" <<  endl;
		//cin >> n;
		//cout << "fibonacci(" << n << ")=" << fibonacci(n) << endl;
		int base;
		cout << "input your digit and base" << endl;
		cin >> input; 
		cin >> base;
		cout << "output: " << digit2base(input.c_str(), base) << endl; 
	}

		
}	
