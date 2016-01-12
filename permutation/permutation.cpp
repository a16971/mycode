#include<cstring>
#include<iostream>

using namespace std;

void permuteUtil(char*, char*, bool*, int, int);
int g_permuteCount = 0;

void permutation(char* inString)
{
	bool* used = NULL;
	char* out = NULL;
	int length = 0;

	if(!inString) return;
	
	length = strlen(inString);

	out = new char[length + 1];
	out[length] = '\0';

	if(!out) return;

	used = new bool[length]; 
	
	for( int i = 0; i < length; i++)
		used[i] =  false;

	permuteUtil(inString, out, used, length, 0);

	delete[] out;
	delete[] used;

	return;
}

void permuteUtil(char* in, char* out, bool used[], int len, int currPos)
{
	if(currPos == len) 
	{
		cout << out << ",  " << ++g_permuteCount  << endl;
		return;
	}

	for(int i = 0; i < len; i++)
	{
		if(!used[i])
		{
			used[i] = true;
			out[currPos] = in[i];
			permuteUtil(in, out, used, len, currPos + 1);
			used[i] = false;
		}
	}
}

int main(void)
{
	char s[] = "1234";
	permutation(s);
	return 1;
}
