#pragma once
#include "pch.h"
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class Divisor : public ExpressionEvaluator, public IShuffle {
public:
	Divisor();
	Divisor(int n);
	
	double Calculate();

	void logToScreen();
	void logToFile(const std::string& FileName);

	void shuffle();
	void shuffle(size_t left, size_t right);

	~Divisor();
};