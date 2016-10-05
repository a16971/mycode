#include "Deck.h"
#include <string>
#include <iostream>

using namespace std;

const string Deck::FACES[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const string Deck::SUITS[4] = {"HEART","SPADE","DIAMOND",""};

Deck::Deck()
{
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			
