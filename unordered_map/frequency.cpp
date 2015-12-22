#include <tr1/unordered_map>
#include <iostream> 
#include <cassert> 
#include <string>
#include <fstream>
#include <cstring> 
#include <stdio.h> 

using namespace std;


std::tr1::unordered_map<string,  long long> g_hashmap;

void word_count(tr1::unordered_map<char, int> m, char* word)
{
	if(!word) return;
	
}

int main( int argc, char **argv)
{
	string line;
	ifstream myfile(argv[1]);
	const char delimeter[] = " `-=+_)(*&^%$#@!~,./';:[]<>|\"\\";

	if(myfile.is_open())
	{
		int i = 0; 
		while(getline(myfile, line) && i < 10000000 )
		{
//			char* cstr = new char[line.length()+1];
			static char cstr[2000];
			std::strcpy(cstr, line.c_str());
			
			char* token =  strtok(cstr, delimeter);
			
			i++;	
			while(token != NULL)
			{
				string stoken(token);
				std::tr1::unordered_map<string, long long>::iterator it;
				if((it = g_hashmap.find(stoken)) != g_hashmap.end())
				{	
					it->second++;
					cout << it->first << " is " << it->second << endl;
				}else
				{
					cout << token << " is added" << endl;
					g_hashmap[stoken] = 1;
				}
					
				token = strtok(NULL, delimeter);
			}
		//	delete cstr;						
			
		}

		myfile.close();
	}else
		cout << "unable to open file" << endl;

	cout << "hashmap size: " << g_hashmap.size() << endl;
	for(std::tr1::unordered_map<string, long long>::iterator it = g_hashmap.begin(); it != g_hashmap.end(); ++it)
		cout << it->first << " : " << it->second << endl;


	return 0;

}

	
