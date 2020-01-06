#include "Pharmacy.h"
using namespace std;

Pharmacy::Pharmacy() {
	type_ = false;
}

Pharmacy::Pharmacy(const string& title, const string& address, int YearOfFoundation, int number, int TotalProfit, int profit, bool type) :
	Magazine(title, address, YearOfFoundation, number, TotalProfit, profit), type_(type)
{
}

Pharmacy::~Pharmacy() {

}

void Pharmacy::set_type(const bool type) {
	type_ = type;
}
bool Pharmacy::get_type() const {
	return type_;
}

void Pharmacy::payTax() {
	TotalProfit_ = TotalProfit_ - (int)(profit_ * 30);
}

void Pharmacy::Print() 
{
	cout << "Title: "              << title_            << endl;
	cout << "Address: "            << address_          << endl;
	cout << "Year of foundation: " << YearOfFoundation_ << endl;
	cout << "Number: "             << number_           << endl;

	payTax();
	cout << "Total profit: "       << TotalProfit_      << endl;

	cout << "Profit: "             << profit_           << endl;

	if (type_ == true) {
		cout << "Type: " << "around the clock" << endl;
	}
	else cout << "Type: " << "not arouns the clock" << endl;
	cout << endl << endl;
}