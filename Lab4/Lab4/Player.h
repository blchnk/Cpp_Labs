#pragma once
#include "Hand.h"

class Player
{
private:
	Hand* hand_;
	int balance_;
	int bet_;

public:

	Player();
	~Player();
	Hand* getHand()const;
	int getBalance()const;
	int getBet()const;
	
	void setBet(int bet);

	int& NewBet();

	void ResetHand();
	void addBalance(int money);
	void subBalance(int money);

	void MakeBet();
};