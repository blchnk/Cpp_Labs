#pragma once

#include "Magazine.h"

class Boutique : public Magazine {
protected:
	string WorkingTime_;
	int NumberOFCustumersWithDiscount_;
public:
	Boutique();
	Boutique(const string& title, const string& address, int YearOfFoundation, int number, int TotalProfit, int profit, string WorkingTime, int NumberOFCustumersWithDiscount);

	~Boutique();

	void set_WorkingTime(const string& WorkingTime);
	void set_NumberOFCustumersWithDiscount(const int NumberOFCustumersWithDiscount);

	string get_WorkingTime() const;
	int get_NumberOFCustumersWithDiscount() const;

	void payTax();

	void Print();
};