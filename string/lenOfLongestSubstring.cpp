#include <string>
#include <iostream>

using namespace std;

int lenOfLongestSubstring(string s)
{
	int len = s.length();
	int i = 0, j = 0;
	bool exist[256] = { false };
	int maxLen = 0;

	while(j < len)
	{
		if(!exist[s[j]])
		{
			exist[s[j]] = true;
			j++;
			
		}else
		{

			maxLen = maxLen > j-i? maxLen: j-i;
			while(i < j - 1)
			{
				exist[s[i]] = false;
				i++;
			}
			i++; j++;
		}
	}

	maxLen = maxLen > len - i? maxLen : len - i;
	return maxLen;
}

int main(void)
{

	string s1("abcabcbbb");
	string s2("a123456789aaaa");


	cout << "maxlen of " << s1 << lenOfLongestSubstring(s1) << endl;
	cout << "maxlen of " << s2 << lenOfLongestSubstring(s2) << endl;

	return 0;
}

	
