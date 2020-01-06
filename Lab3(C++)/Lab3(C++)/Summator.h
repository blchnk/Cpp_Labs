#pragma once
#include "pch.h"
#include "ExpressionEvaluator.h"

class Summator: public ExpressionEvaluator {
public:
	Summator();
	Summator(int);

	double Calculate();

	void logToScreen();
	void logToFile(const std::string& FileName);

	~Summator();
};