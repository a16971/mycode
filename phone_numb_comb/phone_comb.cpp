#include <iostream> 
#include <string>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

//std::tr1::unordered_map<int, string> key_pad = {
	void print_result(vector<char> result)
{
	cout << "result: ";
	for (vector<char>::iterator i = result.begin(); i != result.end(); i++)
		cout << *i;
	cout << endl;
}
void DFS_phone(char* digits)
{
	string key[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<char> result;
	stack<pair<int, int> > mystack;

	if (!digits || strlen(digits) == 0)
		return;
	int i = 0;

	int digit = digits[i] - '0';


//	for (int j = 0; j < key[digit].length(); j++)
//	{
		pair<int, int> p(0, 0);

		mystack.push(p);

		while (!mystack.empty())
		{
			p = mystack.top();
			result.push_back(key[digits[p.first]-'0'][p.second]);
			mystack.pop();
			print_result(result);

			if (p.first < strlen(digits))
			{
				for (int k = 0; k <= key[digits[p.first + 1] - '0'].length(); k++)
				{
					pair<int, int> pp(p.first + 1, k);
					cout << "push adj to stack: <" << p.first + 1 << ", " << k << ">";
					mystack.push(make_pair(p.first +1, k));
					cout << "top pair: <" << mystack.top().first << ", " << mystack.top().second << ">\n ";
				}

			}
			else
				result.push_back('\n');
		}
//	}

}

	
int main(void)
{
	char input[] = "234";
	DFS_phone(input);
	return 0;
}
