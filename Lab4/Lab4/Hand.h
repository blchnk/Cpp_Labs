#pragma once
#include <vector>
#include "Card.h"
#include <iostream>
class Hand
{

private:
	vector<Card*> cards;

public:

	Hand();
	~Hand();

	void addCard(Card*);
	int getCountCard();
	int CalculateScore();
	void PrintCards();
	vector<Card*> getCards()const;





};

