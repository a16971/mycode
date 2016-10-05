#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <string>
#include <vector>

using namespace std;

class Deck
{
private:
	static const string FACES[13];
	static const string SUITS[4];
	vector<Card> m_cards;

public:
	void shuffleCards();
	Card drawOneCard();
	Deck();
	~Deck();
};

#endif
