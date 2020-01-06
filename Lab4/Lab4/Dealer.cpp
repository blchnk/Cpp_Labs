#include "Dealer.h"


Dealer::Dealer() {
	hand_ = new Hand();
}

Dealer::~Dealer() {
	delete hand_;
}

Hand* Dealer::getHand()const {
	return hand_;
}

void Dealer::ResetHand() {
	delete hand_;
	hand_ = new Hand();
}