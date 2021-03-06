#include "pch.h"
#include <iostream>
#include <cstdio>;
using namespace std;

/*
Написать программу, которая преобразует одномерный массив (1D) в двумерный (2D)
(или наоборот), в соответствии с вариантом. Необходимо оформить в отдельных
функциях код следующих действий: 1) инициализация массива; 2) вывод массива; 3)
преобразование массива (создание нового массива с другой структурой). Память под
массивы выделять динамически и для доступа к элементам использовать указатели.

Преобразование: 2D → 1D. Двумерный массив 5х5 целых чисел необходимо выложить
в один ряд по элементам слева направо и сверху вниз, исключая все элементы на
четных строках.
Инициализация: заполнить массив факториалами: x[i][j] = ( i+j )! 
Вывод на экран: на каждый элемент массива отвести 8 позиций.
*/

void freeArray2D(int** arr2D, size_t rows) {//Освобождаем память
	for (size_t i = 0; i < rows; i++) {
		delete[] * (arr2D + i);
	}
	delete[] arr2D;
}

void printArray2D(int** arr, size_t row, size_t colum) {//Вывод двумерного массива
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < colum; j++) {

			//cout << *(*(arr + i) + j) << " ";
			printf("%8d", *(*(arr + i) + j));
		}
		cout << endl;
	}
	cout << endl;
}

void printArray1D(int* arr, size_t len) {//Вывод одномерного массива
	for (size_t i = 0; i < len; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

double fac(int number)//Вычисляем факториал 
{
	if (number == 0) {
		return 1;
	}
	else
		if (number == 1) {
			return 1;
		}
		else {
			return number * fac(number - 1);
		}
}

void IninitializeArray(int** arr, size_t row, size_t colum) {//Заполняем двумерный массив факториалами 
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < colum; j++) {
			*(*(arr + i) + j) = fac(i + j);
		}
	}
}

int* makeArray1D(int** arr2D, size_t rows, size_t cols) {//Колдуем двумерный к одномерному

	int* arr1D = new int[rows*cols];

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if ((i + 1) % 2 != 0) {
				arr1D[i * cols + j] = arr2D[i][j];
			}else arr1D[i * cols + j] = 0;
						
		}
	}
	return arr1D;
}

int main()
{
	const size_t row = 5;
	const size_t colum = 5;

	int** arr2D = new int*[row];

	for (size_t i = 0; i < row; i++) {

		*(arr2D + i) = new int[colum];
	}
	IninitializeArray(arr2D, row, colum);
	printArray2D(arr2D, row, colum);
	cout << endl << endl;

	int* arr1D = makeArray1D(arr2D, row, colum);
	printArray1D(arr1D, row * colum);
	freeArray2D(arr2D, row);
}