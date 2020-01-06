#pragma once

#include <iostream>
#include "Magazine.h"
using namespace std;

Magazine::Magazine() {
	title_ = "None";
	address_ = "None";
	YearOfFoundation_ = 0;
	number_ = 0;
	TotalProfit_ = 0;
	profit_ = 0;
}

Magazine::Magazine(const string& title, const string& address, int YearOfFoundation, int number, int TotalProfit, int profit) :
	title_(title), address_(address), YearOfFoundation_(YearOfFoundation), number_(number), TotalProfit_(TotalProfit), profit_(profit)
{
}

Magazine::~Magazine() {

}

//set
void Magazine::set_title(const string& title) {
	title_ = title;
}
void Magazine::set_address(const string& address) {
	address_ = address;
}
void Magazine::set_YearOfFoundation(const int YearOfFoundation) {
	YearOfFoundation_ = YearOfFoundation;
}
void Magazine::set_number(const int number) {
	number_ = number;
}
void Magazine::set_TotalProfit(const int TotalProfit) {
	TotalProfit_ = TotalProfit;
}
void Magazine::set_profit(const int profit) {
	profit_ = profit;
}

//get
string Magazine::get_title() const {
	return title_;
}
string Magazine::get_address() const {
	return address_;
}
int Magazine::get_YearOfFoundation() const {
	return YearOfFoundation_;
}
int Magazine::get_number() const {
	return number_;
}
int Magazine::get_TotalProfit() const {
	return TotalProfit_;
}
int Magazine::get_profit() const {
	return profit_;
}

void Magazine::serialize() {
	string path = title_ + ".txt";
	ofstream fout;
	fout.open(path);
	fout << title_ << endl;
	fout << address_ << endl;
	fout << YearOfFoundation_ << endl;
	fout << number_ << endl;
	fout << TotalProfit_ << endl;
	fout << profit_ << endl;
	fout.close();
}

void Magazine::serialize(const string& filename)
{
	ofstream fout;
	fout.open(filename);
	fout << title_ << endl;
	fout << address_ << endl;
	fout << YearOfFoundation_ << endl;
	fout << number_ << endl;
	fout << TotalProfit_ << endl;
	fout << profit_ << endl;
	fout.close();
}

void Magazine::deserialize()
{
	string path = title_ + ".txt";
	ifstream fin;
	fin.open(path);
	string tmp = "";

	if (fin.is_open())
	{
		while (getline(fin, tmp))
		{
			cout << tmp << endl;
		}
	}
	else(cout << "File cannot be opened!");
}

void Magazine::deserialize(const string& filename)
{
	ifstream fin;
	fin.open(filename);
	string tmp = "";

	if (fin.is_open())
	{
		while (getline(fin, tmp))
		{
			cout << tmp << endl;
		}
	}
	else(cout << "File cannot be opened!");
}