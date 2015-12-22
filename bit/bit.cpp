#include <bitset> 
#include <iostream>
#include <string> 

using namespace std;

bool getBit(int num, int i)
{
	return((num & (1 << i)) != 0);
}

int  setBit(int num, int i)
{
	return num | (1 << i);
}
 
int clearBit(int num, int i)
{
	int mask = ~(1 << i);
	return num & mask;
}
//To clear all bits from the most significant bit through i (inclusive)
int clearBitsMSBThroughI(int num, int i)
{
	int mask = (1 << i) - 1;
	return num & mask;
}

//To clear all bits from i through 0 (inclusive)
int clearBitsIthrough0(int num, int i)
{
	int mask = ~((1 << (i+1)) - 1 );
	return num & mask;
}
	
int main(void)
{
	unsigned char a = 255, b = 0;

	cout << " a = " << std::bitset<8>(a) << endl;
	cout << " b = " << std::bitset<8>(b) << endl;
	cout << " getBit(a,3) = " << bitset<8>(getBit(a, 3)) << endl;
	cout << " setBit(b,3) = " << bitset<8>(setBit(b, 3)) << endl;
	cout << " clearBit(a,3) = " << bitset<8>(clearBit(a, 3)) << endl;
	cout << " clearBitsMSBThroughI(a, 5) = " << bitset<8>(clearBitsMSBThroughI(a, 5)) << endl;
	cout << " clearBitsIthrough0(a, 5) = " << bitset<8>(clearBitsIthrough0(a, 5)) << endl;

	return 0;
}
