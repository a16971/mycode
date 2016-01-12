#include<cstring>
#include<iostream>

using namespace std;

void combineUtil(char* in, char* out, int length, int currOutPos, int startIn);

void combination(char* inString)
{
	if(!inString) return; 

	int length = strlen(inString);
	char * out = new char[length];

	combineUtil(inString, out, length, 0,0);
	
	return;
}

void combineUtil(char* in, char* out, int length, int currOutPos, int startIn)
{

	for(int i = startIn; i < length; i++)
	{
		out[currOutPos] =  in[i];
		out[currOutPos + 1] = '\0';
		cout << out << endl;
	
		if(i < length - 1)
			combineUtil(in, out, length, currOutPos + 1, i + 1);
	} 
	return;
} 

int main(void)
{
	char s[] = "1234";
	
	combination(s);

	return 1;
}

