/*
Написать свой аналог стандартной функции обработки строк из файла cstring, в
соответствии с вариантом. В функции main на тестовых данных продемонстрировать
результат работы как стандартной функции, так и собственной версии. Ввод-вывод
данных организовать средствами cstdio.

Функция strcmp.
Формат int strcmp(const char* s1, const char* s2).
Функция сравнивает строку s1 со строкой s2 в лексикографическом порядке. Если s1<s2,
то результат равен -1, если s1=s2, то 0, если s1>s2, то 1.
*/
#include "pch.h"
#include <cstdio>
#include <cstring>

int MYstrcmp(const char* s1, const char* s2) {
	while (*s1 && *s2) {
		if (*s1 < *s2) return -1;
		if (*s1 > *s2) return 1;
		++s1; ++s2;
	}
	return *s1? -1 : *s2? 1 : 0;
}

int main()
{
	char s1[] = "A";
	char s2[] = "B";
	
	int standart_result = strcmp(s1, s2);
	int my_result = MYstrcmp(s1,s2);
	printf("Defolt function: %d\n", standart_result);
	printf("My function: %d", my_result);
	
}


