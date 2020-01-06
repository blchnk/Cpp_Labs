#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include <exception>

class Game
{
private:
	const int count_deck_;
	Deck* decks_;
	int minBet_;
	int maxBet_;
	Dealer* dealer_;
	Player* player_;
	int select_;
	bool first_move;
public:

	Game(int count_deck,int minBer,int maxBet);
	~Game();

	void Play();
	void PrintStatus();
	void Dowble();

	void Won();
	void Lose();
	void WonBlackJack();
	int& setSelect();

	bool TakeMore();


};

