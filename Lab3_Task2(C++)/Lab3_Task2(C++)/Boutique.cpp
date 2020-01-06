#include <iostream>
#include "Boutique.h"
using namespace std;

Boutique::Boutique() {
	WorkingTime_ = "None";
	NumberOFCustumersWithDiscount_ = 0;
}

Boutique::Boutique(const string& title, const string& address, int YearOfFoundation, int number, int TotalProfit, int profit, string WorkingTime, int NumberOFCustumersWithDiscount) :
	Magazine(title, address, YearOfFoundation, number, TotalProfit, profit), WorkingTime_(WorkingTime), NumberOFCustumersWithDiscount_(NumberOFCustumersWithDiscount) 
{
}

Boutique::~Boutique() {

}

void Boutique::set_WorkingTime(const string& WorkingTime) {
	WorkingTime_ = WorkingTime;
}
void Boutique::set_NumberOFCustumersWithDiscount(const int NumberOFCustumersWithDiscount) {
	NumberOFCustumersWithDiscount_ = NumberOFCustumersWithDiscount;
}

string Boutique::get_WorkingTime() const {
	return WorkingTime_;
}
int Boutique::get_NumberOFCustumersWithDiscount() const {
	return NumberOFCustumersWithDiscount_;
}

void Boutique::payTax() {
	TotalProfit_ = TotalProfit_ - (int)(profit_ * 30 * 0.20);
}

void Boutique::Print()
{
	cout << "Title: " << title_ << endl;
	cout << "Address: " << address_ << endl;
	cout << "Year of foundation: " << YearOfFoundation_ << endl;
	cout << "Number: " << number_ << endl;

	payTax();
	cout << "Total profit: " << TotalProfit_ << endl;

	cout << "Profit: " << profit_ << endl;
	cout << "Working time: " << WorkingTime_ << endl;
	cout << "Number of custumers with discount: " << NumberOFCustumersWithDiscount_ << endl;
}