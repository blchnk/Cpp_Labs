#pragma once

#include "Magazine.h"

class Pharmacy : public Magazine {
protected:
	bool type_;
public:
	Pharmacy();
	Pharmacy(const string& title, const string& address, int YearOfFoundation, int number, int TotalProfit, int profit_, bool type);

	~Pharmacy();

	void set_type(const bool type);

	bool get_type() const;

	void payTax();

	void Print();
};