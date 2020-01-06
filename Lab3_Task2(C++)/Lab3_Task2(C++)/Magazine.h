#pragma once

#include "ITaxPayment.h"
using namespace std;

class Magazine : public ITaxPayment {
protected:
	string title_;
	string address_;
	int YearOfFoundation_;
	int number_;
	int TotalProfit_;
	int profit_;

public:
	Magazine();
	Magazine(const string& title, const string& address, int YearOfFoundation, int number, int TotalProfit, int profit);

	//destructor
	virtual ~Magazine();

	//set
	void set_title(const string& title);
	void set_address(const string& address);
	void set_YearOfFoundation(const int YearOfFoundation);
	void set_number(const int number);
	void set_TotalProfit(const int TotalProfit);
	void set_profit(const int profit);

	//get
	string get_title()const;
	string get_address()const;
	int get_YearOfFoundation()const;
	int get_number()const;
	int get_TotalProfit()const;
	int get_profit() const;

	virtual void Print() = 0;

	void serialize();
	void serialize(const string& filename);
	void deserialize();
	void deserialize(const string& filename);
};
