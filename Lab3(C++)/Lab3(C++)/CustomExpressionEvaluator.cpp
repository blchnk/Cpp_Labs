#pragma once
#include "pch.h"
#include "CustomExpressionEvaluator.h"
#include <iostream>
using namespace std;

CustomExpressionEvaluator::CustomExpressionEvaluator() {

}

CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n){

}

double CustomExpressionEvaluator::Calculate() {
	double tmp = operands[0];
	for (int i = 1; i < length; i++) {
		if (i % 2 != 0) tmp = tmp - operands[i];
		else tmp = tmp + operands[i];
	}
	return tmp;
}

void CustomExpressionEvaluator::logToScreen() {
	cout << "CusomExpressionEvaluator [" << length << "]: ";
	if (operands[0] > 0) cout << operands[0];
	else cout << "(" << operands[0] << ")";

	for (int i = 1; i < length; i++) {
		if(operands[i] > 0 && i % 2 != 0) cout << " - (" << operands[i] << ") ";
		else cout << " + (" << operands[i] << ") ";
	}
	cout << " = " << Calculate() << endl << endl;
}

void CustomExpressionEvaluator::logToFile(const std::string& FileName) {
	cout << Calculate();
}

void CustomExpressionEvaluator::shuffle() {
	double* temp = new double[length];
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (operands[i] < 0) {
			temp[count] = operands[i];
			count++;
		}
	}
	for (int i = 0; i < length; i++) {
		if (operands[i] >= 0) {
			temp[count] = operands[i];
			count++;
		}
	}
	for (int i = 0; i < length; i++)
		operands[i] = temp[i];
	delete[]temp;
}

void CustomExpressionEvaluator::shuffle(size_t left, size_t right) {
	if (operands[left - 1] < 0 && operands[right - 1] >= 0) {
		double temp = operands[left - 1];
		operands[left - 1] = operands[right - 1];
		operands[right - 1] = temp;
	}
}

CustomExpressionEvaluator::~CustomExpressionEvaluator() {
	delete[] operands;
}