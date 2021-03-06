#pragma once
#include "pch.h"
#include <iostream>
#include "ExpressionEvaluator.h"
#include "Summator.h"
#include "Divisor.h"
#include "CustomExpressionEvaluator.h"
#include "IShuffle.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	const int len = 3;
	ExpressionEvaluator* evaluators[len];

	evaluators[0] = new Summator(7);
	evaluators[1] = new Divisor(4);
	evaluators[2] = new CustomExpressionEvaluator(5);

	double* sum_operands = new double[7]{ 5, 12.5, 9, -1.5, -9.5, 0, 11 };
	evaluators[0]->setOperands(sum_operands, 7);

	//double* divisor_operands = new double[4] {100, -4, 2.5, -4};
	evaluators[1]->setOperand(0, 100);
	evaluators[1]->setOperand(1, -4);
	evaluators[1]->setOperand(2, 2.5);
	evaluators[1]->setOperand(3, -4);

	double* custom_operands = new double[5]{ 5, 4, -2, 9, 3 };
	evaluators[2]->setOperands(custom_operands, 5);

	for (int i = 0; i < len; i++) {
		evaluators[i]->logToScreen();
		evaluators[i]->logToFile("log.txt");
	}

	for (int i = 0; i < 3; i++) {
		IShuffle* is = dynamic_cast<IShuffle*>(evaluators[i]);
		if (is) {
			is->shuffle();
			evaluators[i]->logToScreen();
		}
	}

	for (int i = 0; i < 3; i++)	delete evaluators[i];
}

