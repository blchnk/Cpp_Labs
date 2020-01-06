#pragma once
#include "Hand.h"



class Dealer
{
private:
	Hand* hand_;

public:

	Dealer();
	~Dealer();
	Hand* getHand()const;
	void ResetHand();


};

