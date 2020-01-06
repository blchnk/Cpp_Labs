#pragma once
#include "pch.h"
#include <iostream>
#include "ExpressionEvaluator.h";
using namespace std;

ExpressionEvaluator::ExpressionEvaluator() {
	length = 20;
	operands = new double[20]{0};
}

ExpressionEvaluator::ExpressionEvaluator(int n) {
	length = n;
	operands = new double[n]{0};
}

void ExpressionEvaluator::setOperand(size_t pos, double value) {
	operands[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], size_t n) {
	delete[] operands;
	length = n;
	operands = new double[n];
	for (int i = 0; i < n; i++) operands[i] = ops[i];
}

ExpressionEvaluator::~ExpressionEvaluator() {
	delete[] operands;
}

