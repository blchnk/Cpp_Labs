#include "Hand.h"

Hand::Hand(){}


Hand::~Hand(){
	for (int i = 0; i < cards.size(); i++) {

		delete cards[i];
	}
}


void Hand::addCard(Card* card) {
	cards.push_back(card);
}

int Hand::getCountCard(){
	return cards.size();
}

int Hand::CalculateScore() {

	int summ = 0;

	for (int i = 0; i < cards.size(); i++) {

		if (summ > 21 && cards[i]->getScore() == 11) {
			summ += 1;
		}
		else {
			summ += cards[i]->getScore();
		}
	}
	return summ;
}

void Hand::PrintCards() {
	for (int i = 0; i < cards.size(); i++) {
		cout << *cards[i]<<"  ";
	}
}

vector<Card*> Hand::getCards()const {
	return cards;
}