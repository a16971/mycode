#include <iostream>
#include <tr1/unordered_map>
#include <string> 
#include <sstream> 
using namespace std;
using namespace std::tr1;

class SpreadSheet
{
	const static int MAX_CELL_INDEX = 65535;
	unordered_map<int, unordered_map<int, string> > data;

	bool  validateIndex(int row, int column)
	{	
		int ret = true;
		if( row < 0 || row > MAX_CELL_INDEX || column < 0 || column > MAX_CELL_INDEX)
		{
			ret = false;
			cout << "range error." << endl;
		}
		return ret;
	}

public:

	SpreadSheet(){}

	void setValue(int row, int column, string value)
	{
		if(!validateIndex(row, column))
			return;
		data[row][column] = value;
		
	}

	string getValue(int row, int column)
	{
		if(!validateIndex(row, column))
			return NULL;
		
		if(data.find(row) != data.end())
			return data[row][column];
		
		return NULL;
		
	}

}; 

int main(void)
{
	SpreadSheet sp;
	string s = "ssssss";
	sp.setValue(1000, 2000,s);
	sp.setValue(-1, 20, s);
	cout << sp.getValue(1000, 2000) << endl;
//	cout << sp.getValue(-1,20) << endl;
	for(int i = 1; i < 6500; i++)
		for(int j = 1; j < 6500; j++)
		{
			string s;
			ostringstream out;
			out << i << "," << j;
			s = out.str();
			sp.setValue(i,j,s);

		}

	for(int i = 1; i < 6500; i++)
		for(int j = 1; j < 6500; j++)
		{
			cout << sp.getValue(i,j) << endl;

		}

	return 1;
} 
