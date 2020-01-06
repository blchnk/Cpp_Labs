#include "Player.h"

Player::Player() {
	hand_ = new Hand();
	balance_ = 10000;
	bet_ = 0;
}

Player::~Player() {
	delete hand_;
}

int Player::getBalance()const {
	return balance_;
}

int Player::getBet()const{
	return bet_;
}

Hand* Player::getHand()const {
	return hand_;
}

void Player::setBet(int bet) {
	bet_ = bet;
}

int& Player::NewBet() {
	return bet_;
}

void Player::addBalance(int money) {
	balance_ += money;
}

void Player::subBalance(int money) {
	balance_ -= money;
}

void Player::ResetHand() {
	delete hand_;
	hand_ = new Hand();
}

void Player::MakeBet() {
	balance_ -= bet_;
}