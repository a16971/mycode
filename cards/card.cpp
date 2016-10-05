#include "card.h"



Card::Card(int face, int suit):m_face(face),m_suit(suit)
{
}

Card::~Card()
{
}

void Card::setFace(int face)
{
	m_face = face;
}

void Card::setSuit(int suit)
{
	m_suit = suit;
}

int Card::getFace() const
{
	return m_face;
}

int Card::getSuit() const
{
	return m_suit;
}

