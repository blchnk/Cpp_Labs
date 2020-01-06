#pragma once
#include "pch.h"
#include "Summator.h"
#include <iostream>
using namespace std;

Summator::Summator() {
	
}

Summator::Summator(int n) :ExpressionEvaluator(n) {

}

double Summator::Calculate() {
	double tmp = 0;
	for (int i = 0; i < length; i++) {
		tmp += operands[i];
	}
	return tmp;
}

void Summator::logToScreen() {
	cout << "Summator [" << length << "]: ";
	if (operands[0] > 0) cout << operands[0];
	else cout << "(" << operands[0] << ")";

	for (int i = 1; i < length; i++) {
		if (operands[i] > 0) cout << " + " << operands[i];
		else cout << " + (" << operands[i] << ") ";
	}
	cout << " = " << Calculate() << endl << endl;
}

void Summator::logToFile(const std::string& FileName) {
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

	fout << " Total < " << length << " >" << std::endl;
	fout << "Result < " << this->Calculate() << " >" << std::endl;

	fout.close();
}

Summator::~Summator() {
	delete[] operands;
}