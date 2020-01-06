#pragma once
#include "pch.h"
#include "ILoggable.h"

class ExpressionEvaluator: public ILoggable 
{
public:
	double* operands;
	int length;
	
	ExpressionEvaluator();
	ExpressionEvaluator(int);

	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);

	virtual double Calculate() = 0;

	virtual ~ExpressionEvaluator();
};