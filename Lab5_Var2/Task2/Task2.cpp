#define _CRT_SECURE_NO_WARNINGS //Без него не работает, поэтому пусть будет

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <iterator>
#include <functional>

using namespace std;

int main()
{
	map<string, int> vocabulary;	  //словарь загружаемых слов
	map<string, int>::iterator IT;    //итератор по словарю

	ifstream fout("Sonnets.txt", ios_base::in);

	if (fout.is_open()) {

		char text[1000];

		while (!fout.eof()) {						//пока файл не закончился 
			fout.getline(text, 1000);			    //считывает, пока не наберёт тысячу символов
			char* substr = strtok(text, ".,:!;? "); //разбиение большой строки на подстроки с разделяющими символами

			while (substr != 0)						//пока есть слова в массиве
			{
				string word = substr;											//переменная для текущей обрабатываемой строки
				transform(word.begin(), word.end(), word.begin(), ::tolower);	//переводит все буквы в нижний регистр
				IT = vocabulary.find(word);										//ищет элемент с конкретным ключем => IT это наше слово с ключем

				if (IT != vocabulary.end()) { IT->second++; }					  //если элемент не последний, увеличиваем КЛЮЧ пары
				else { vocabulary.insert(std::pair<std::string, int>(word, 1)); } //иначе вставляем в словарь пару

				substr = strtok(NULL, ".,:!;? ");	//обнуляем временную строку
			}
		}




		multimap<int, string, greater<>> newVocabulary;   //словарь подходящих слов
		multimap<int, string, greater<>>::iterator newIT; //итератор по подходящим словам

		for (IT = vocabulary.begin(); IT != vocabulary.end(); IT++)							//сначала и до конца словаря
			if (IT->first.size() > 3 && IT->second >= 7)									//если в слове больше 3 букв и оно встречается больше 7 раз 
				newVocabulary.insert(std::pair<int, std::string>(IT->second, IT->first));   //вставляем в новый словарь подходящее слово



		//вывод
		for (newIT = newVocabulary.begin(); newIT != newVocabulary.end(); newIT++)
			std::cout << newIT->first << " : " << newIT->second << std::endl;


	}
	else { printf("Can't open the file(there was an obscene joke)\n"); }
}
