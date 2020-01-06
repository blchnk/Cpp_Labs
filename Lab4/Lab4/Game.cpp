#include "Game.h"

Game::Game(int count_deck, int minBet, int maxBet) :count_deck_(count_deck), minBet_(minBet), maxBet_(maxBet) {

	decks_ = new Deck[count_deck_];
	for (int i = 0; i < count_deck_; i++) {
		decks_[i].Shuffle();
	}

	dealer_ = new Dealer();
	player_ = new Player();
	first_move = true;
}

Game::~Game() {

	delete[] decks_;
	delete dealer_;
	delete player_;
}

void Game::PrintStatus() {
	cout << "Decks:";
	for (int i = 0; i < count_deck_; i++)
		cout << " [" << decks_[i].getSize() << "] ";

	cout <<endl<< "Dealer:";
	dealer_->getHand()->PrintCards();

	cout << endl << "You:";
	player_->getHand()->PrintCards();
	cout << endl << endl;
}

void Game::Lose() { //Проигрыш игрока
	PrintStatus();
	player_->subBalance(player_->getBet());
	cout << "You lose!"<<endl<<"Youe balance: "<<player_->getBalance()<< endl<<"Your scope: "<<player_->getHand()->CalculateScore()<<endl<<"Dealer's score: "<< dealer_->getHand()->CalculateScore()<<endl;
	player_->ResetHand();
	dealer_->ResetHand();
}

void Game::Won() { //победа игрока

	PrintStatus();
	player_->addBalance(2 * player_->getBet());
	cout << "You Won!" << endl << "Youe balance: " << player_->getBalance() << endl << "Your scope: " << player_->getHand()->CalculateScore() << endl << "Dealer's score: " << dealer_->getHand()->CalculateScore() << endl;
	player_->ResetHand();
	dealer_->ResetHand();
}

void Game::WonBlackJack() { //Победа с блекджеком 
	PrintStatus();

	cout << "BlackJack" << endl;
	player_->addBalance(2.5 * player_->getBet());
	cout << "You Won!" << endl << "Youe balance: " << player_->getBalance() << endl << "Your scope: " << player_->getHand()->CalculateScore() << endl << "Dealer's score: " << dealer_->getHand()->CalculateScore() << endl;
	player_->ResetHand();
	dealer_->ResetHand();	
}

bool Game::TakeMore() {
	try {
		player_->getHand()->addCard(decks_[rand() % count_deck_].pop());

		if (player_->getHand()->CalculateScore() > 21) {
			throw "Too much";
		}
		else return true;
	}
	catch (...) {
		Lose();
		return false;
	}
}

void Game::Dowble() {
	player_->addBalance(player_->getBet() / 2);
	player_->setBet(player_->getBet() * 2);
}

int& Game::setSelect() {

	return select_;
}

void Game::Play() {

	int all_count_cards = 0;
	cout << "Lets rock!!!" << endl<<endl;
	while (true) {

		for (int i = 0; i < count_deck_; i++) {
			all_count_cards += decks_[i].getSize();
		}

		if (all_count_cards < 52 * count_deck_ / 3) {

			delete[]decks_;
			decks_ = new Deck[count_deck_];
			for (int i = 0; i < count_deck_; i++) {
				decks_[i].Shuffle();
			}
		}


		cout << "Your balance: " << player_->getBalance() << endl;
		cout << "Min bet: " << minBet_ << endl << "Max bet: " << maxBet_ << endl;
		cout << "Place your bet: ";


		cin >> player_->NewBet();
		if (!cin) {
			cout << "Uncorrect values" << endl;
			break;
		}
		else
			if ((player_->getBalance() - player_->getBet()) < 0) {
				cout << "You have no much money";
				break;
			}
			else
				if (player_->getBet() < minBet_ || player_->getBet() > maxBet_) {
					cout << "Uncorrect bet" << endl;
					break;
				}
				else {
					player_->MakeBet();
				}
		cout<<endl << "Your balance: " << player_->getBalance() << endl;
		cout << "Current Bet: " << player_->getBet() << endl << endl;


		player_->getHand()->addCard(decks_[rand() % count_deck_].pop());
		dealer_->getHand()->addCard(decks_[rand() % count_deck_].pop());
		player_->getHand()->addCard(decks_[rand() % count_deck_].pop());

		PrintStatus();

	


		while (true) {

			if (player_->getHand()->getCards()[0]->getScore() == 10 && player_->getHand()->getCards()[1]->getName() == 'A') {
				WonBlackJack();
				break;
			}
			else {
				
				cout << "1.More" << endl << "2.Enough" << endl;
				if (first_move) {
					cout << "3.Dowble bet?" << endl;
					first_move = false;
				}
			}

			cin >> setSelect();
			if (!cin) {
				cout << "Uncorrect" << endl;
				select_ = 0;
			}

			if (select_ == 1) {

				if (!TakeMore()) break;
			}

			if (select_ == 2) {
				int dealer_score = dealer_->getHand()->CalculateScore();
				int player_score = player_->getHand()->CalculateScore();

				while (dealer_score<=16)
				{
					dealer_->getHand()->addCard(decks_[rand() % count_deck_].pop());
					dealer_score = dealer_->getHand()->CalculateScore();
				}


				if (dealer_score > 21) {
					Won();
					break;
				}

				if (dealer_score <= 21 && dealer_score < player_score) {
					Won();
					break;
				}

				if (dealer_score <= 21 && dealer_score >= player_score) {

					//Если счёт игрока == 21
					if (player_score == 21) {

						//Если у игрока просто 21 очко, то проигрыш
						if (player_->getHand()->getCountCard() > 2) {
							Lose();
							break;
						}
					}
					else {
						//Если у дилера больше чем у игрока или блек джек - игрок проиграл
						Lose();
						break;
					}

				}

				if (select_ == 3 && first_move) {
					Dowble();
				}
			}

		}
		select_ = 0;
		while (select_!=2) {

			cout << "1.Play on" << endl << "2.Finish game" << endl << endl;

			cin >> setSelect();
			if (!cin) {
				cout << "Uncorrect" << endl;
				select_ = 0;
			}

			if (select_ == 1) {
				system("cls");
				first_move = true;
				break;
			}
		}
		
		if (player_->getBalance() <= 0)
		{
			cout << "You lose all money!" << endl;
			break;
		}

		if (player_->getBalance() >= 100000)
		{
			cout << "Casino lose all money! You are dead!" << endl;
			break;
		}

		if (select_ == 2)break;

	}
}