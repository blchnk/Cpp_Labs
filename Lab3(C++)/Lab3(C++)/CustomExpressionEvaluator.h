#pragma once
#include "pch.h"
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator : public ExpressionEvaluator {
public:
	CustomExpressionEvaluator();
	CustomExpressionEvaluator(int);

	double Calculate();

	void logToScreen();
	void logToFile(const std::string& FileName);

	void shuffle();
	void shuffle(size_t left, size_t right);

	~CustomExpressionEvaluator();
};