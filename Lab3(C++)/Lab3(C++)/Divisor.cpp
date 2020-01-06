#pragma once
#include "pch.h"
#include "Divisor.h"
#include <iostream>

using namespace std;

Divisor::Divisor() {

}

Divisor::Divisor(int n) : ExpressionEvaluator(n) {

}

double Divisor::Calculate() {
	double tmp = operands[0];
	for (int i = 1; i < length; i++) {
		tmp = tmp / operands[i];
	}
	return tmp;
}

void Divisor::logToScreen() {
	cout << "Divisor [" << length << "]: ";
	if (operands[0] > 0) cout << operands[0];
	else cout << "(" << operands[0] << ")";

	for (int i = 1; i < length; i++) {
		if (operands[i] > 0) cout << " / " << operands[i];
		else cout << " / (" << operands[i] << ") ";
	}
	cout << " = " << Calculate() << endl << endl;
}

void Divisor::logToFile(const std::string& FileName) {
	std::ofstream fout;
	fout.open(FileName, std::ios_base::app);

	operands[0] > 0 ?
		fout << operands[0]
		:
		fout << '(' << operands[0] << ')';

	for (int i = 1; i < length; ++i)
	{
		fout << " * ";
		(operands[i] > 0) ? fout << operands[i] : fout << '(' << operands[i] << ')';
	}

	fout << "Total < " << length << " >" << std::endl;
	fout << "Result < " << this->Calculate() << " >" << std::endl;

	fout.close();
}

void Divisor::shuffle() {
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

void Divisor::shuffle(size_t left, size_t right) {
	if (operands[left - 1] < 0 && operands[right - 1] >= 0) {
		double temp = operands[left - 1];
		operands[left - 1] = operands[right - 1];
		operands[right - 1] = temp;
	}
}

Divisor::~Divisor() {
	delete[] operands;
}
