#include "Deck.h"


Deck::Deck() {

	for (int i = 0; i < suits.size(); i++) {
		for (int j = 0; j < value.size(); j++) {
			deck.push_back(new Card(value[j], suits[i]));
		}

}
}

Deck::~Deck() {

	for (int it = 0; it != deck.size(); it++)
		delete deck[it];

	deck.clear();
	value.clear();
	suits.clear();
}

void Deck::Shuffle() {
	for (int i = 0; i < 200; i++)
		swap(deck[rand() % deck.size()], deck[rand() % deck.size()]);
}


int Deck::getSize()const {
	return deck.size();
}

Card* Deck::pop() {

	Card* tmp = new Card(deck[0]->getName(), deck[0]->getSuit());
	deck.erase(deck.begin());
	return tmp;
}

void Deck::Print(){

	for (int i = 0; i < deck.size(); i++) {

		cout << *deck[i]<<endl;
	}

}