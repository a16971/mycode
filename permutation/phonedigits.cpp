#include <iostream>
#include <cstring> 

using namespace std;
#define PHONE_NUM_LEN 7
char getChByDigits(int num, int index)
{
	const char* s[] = {NULL, NULL, "ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

	if(num >=2 && num <= 9) 
		return s[num][index];
	else
		return ' ';
}

void printPhoneNumUtil(int[], char*, int);
void printPhoneNumber(int phone_num[])
{
	if(!phone_num) return;
	char* result = new char[PHONE_NUM_LEN];
	printPhoneNumUtil(phone_num,result,0);
}

void printPhoneNumUtil(int phone_num[], char* result,int curDigit)
{
	if(curDigit == PHONE_NUM_LEN)
	{
		cout << result << endl;
		return;
	}
	
	for(int i = 0; i < 4; i++)
	{
		int curPhoneNum = phone_num[curDigit];
		if(getChByDigits(curPhoneNum, i) == '\0') continue;		
//		if( (curPhoneNum != 7 || curPhoneNum != 9) && i == 3) continue;
		
		result[curDigit] = getChByDigits(curPhoneNum, i);
		
		printPhoneNumUtil(phone_num, result, curDigit + 1);
		
		if(curPhoneNum == 0 || curPhoneNum == 1 ) return;
	}
}

int main(void)
{
	int phone_num[] = {2,2,2,7,7,7,9};

	printPhoneNumber(phone_num);
	return 1;
}

