#ifndef CARD_H
#define CARD_H

#include <string> 

using std::string;


class Card
{
private:
	int m_face;
	int m_suit;

public:
	Card(int face, int suit);
	~Card();
	int getFace() const;
	int getSuit() const;
	void setFace(int face);
	void setSuit(int suit);
};



#endif
