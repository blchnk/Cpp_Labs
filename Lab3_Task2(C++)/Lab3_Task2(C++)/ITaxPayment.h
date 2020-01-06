#pragma once

#include <string>
#include <iostream>
#include <fstream>

class ITaxPayment {
public:
	virtual void payTax() = 0;
};
