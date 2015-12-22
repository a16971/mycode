//add 2 binary strings
//s1 = "100" s2 = "10" s1+s2="110"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/*
string addBinary(string a, string b)
{
	string ret;
	int carry = 0;
//	string::reverse_iterator rita = a.rend(), ritb = b.rend();
 
	for(; rita != a.end() || ritb != b.end( || carry); ++rita, ++ritb)
	{
		int sum = carry;
		
		if(rita != a.end())
			sum += *rita - '0';

		if(ritb != b.end())
			sum += *ritb - '0';
		
		carry = sum / 2;

		ret.push_back(sum % 2 + '0');
	}*/
string addBinary(const char* s1, const char* s2)
{
	string  ret;
	int carry = 0;

	size_t l1 = strlen(s1);
	size_t l2 = strlen(s2);
	int i = 0, j = 0;	

	for(; i < l1 || j < l2 || carry; ++i, ++j)
	{
		int sum = carry;
		if( i < l1 )
			sum += s1[l1 - i - 1] - '0';

		if( j < l2 )
			sum += s2[l2 - j - 1] - '0';

		carry = sum /2;
		
		cout << "sum: " << sum << endl;
		ret.push_back( sum % 2 + '0');
		cout << "sum % 2 + '0'" << sum % 2 + '0' << endl;
	}

	return ret;

}
	
int main(void)
{
	
	cout << addBinary("10000", "11") << endl;
	cout << addBinary("11111", "1") << endl;
	return 0;
}
