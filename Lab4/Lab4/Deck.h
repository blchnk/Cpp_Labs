#pragma once
#include <vector>
#include <iostream>
#include "Card.h"
#include <iterator>
class Deck
{
private:

	vector<Card*> deck;
	vector<char> value = { '2','3','4','5','6','7','8','9','1','J','Q','K','A' };
	vector<char>suits = { char(3),char(4),char(5),char(6) };
	
public:

	Deck();
	~Deck();
	void Shuffle();
	int getSize()const;
	Card* pop();
	void Print();
};

