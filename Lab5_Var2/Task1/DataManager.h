#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

template <typename T>
class DataManager 
{
public:
	DataManager();					//конструктор
	~DataManager();					//деструктор
	void push(T elem);				//добавить один элемент в вектор (данные пишутся в начало набора, остальные смещаются вправо)
	void push(T elems[], int size);	//добавить массив элементов в вектор
	T peek();						//возвращает второй элемент в наборе или 0, если элементов в наборе меньше 2
	T pop();						//извлекает последний элемент

	bool checkLengthOfList();		//проверка на кол-во элементов в массиве

	void downloadFromFile();		//загрузить данные из файла
	void uploadToFile();			//выгрузить данные в файл

	void print();					//вывод элементов на консоль
private:
	vector<T> dataList;
};

template <typename T>
DataManager<T>::DataManager() {
	
}

template <typename T>
DataManager<T>::~DataManager() {
	dataList.clear();
}

template <typename T>
void DataManager<T>::push(T elem) {
	if (checkLengthOfList()) {        //если элементов меньше 64
		dataList.emplace(dataList.begin(), elem);     //запихиваем элемент
	}
	else {
		this->uploadToFile();		  //если элементов 64, то выгружаем их в файл
		dataList.clear();			  //очищаем вектор
		dataList.emplace(dataList.begin(), elem);    //запихиваем элемент
	}
}

template<typename T>
void DataManager<T>::push(T elems[], int size) {
	for (int i = 0; i < size; i++)
		dataList.emplace(dataList.begin(), elems[i]);
}


template<typename T>
T DataManager<T>::peek() {
	if (dataList.size() < 2)
	{
		return 0;
	}
	else 
	{
		return dataList.at(1);//возвращаем второй элемент
	}
}

template<typename T>
T DataManager<T>::pop() {
	return dataList.size() - 1;
}

template <typename T>
bool DataManager<T>::checkLengthOfList() {
	if (dataList.size() < 64) return true;
	else return false;
}

template <typename T>
void DataManager<T>::downloadFromFile() {
	std::ifstream file("dump.dat", std::ios_base::in);
	if (file.is_open()) {
		std::string str;
		std::getline(file, str);

		std::string typeName = typeid(char).name();

		while (str.compare("")) {
			if (typeName == "int")
				this->push(std::stoi(str));


			if (typeName == "double")
				this->push(std::stod(str));


			if (typeName == "char")
				this->push(*(str.c_str()));

			std::getline(file, str);
		}
		printf("DataManager's data loaded successfully.\n");
	}
	else {
		printf("Can't open file. DataManager is empty.\n");
	}
}

template <typename T>
void DataManager<T>::uploadToFile() {
	std::ofstream fout("dump.dut", std::ios_base::app);
	for (int i = 0; i < dataList.size(); i++) {
		fout << dataList[i];
	}
	fout.close();
}

template<typename T>
void DataManager<T>::print() {
	for (int i = 0; i < dataList.size(); i++) {
		cout << dataList[i] << "\t";
	}
	cout << "\n\n" << endl;
}

template <>
class DataManager<char> 
{
public:
	DataManager();						//конструктор
	~DataManager();						//деструктор
	void push(char elem);				//добавить один элемент в вектор (данные пишутся в начало набора, остальные смещаются вправо)
	void push(char elems[], int size);	//добавить массив элементов в вектор
	char peek();						//возвращает второй элемент в наборе или 0, если элементов в наборе меньше 2
	char pop();							//извлекает последний элемент

	//при извлечении символа из набора приводят его к верхнему или нижнему регистру, соответственно
	char popUpper();					
	char popLower();

	bool checkLengthOfList();			//проверка на кол-во элементов в массиве

	void downloadFromFile();			//загрузить данные из файла
	void uploadToFile();				//выгрузить данные в файл

	void print();						//вывод элементов на консоль
private:
	vector<char> dataList;              //виновник моего недосыпа
};

inline DataManager<char>::DataManager() {

}

inline DataManager<char>::~DataManager() {
	dataList.clear();
}

//Сейчас поясню за inline:
//всякий раз когда вы будете вызывать эту функцию, компилятор будет заменять вызов функции фактическим кодом из функции
inline void DataManager<char>::push(char elem) { 
	switch (elem) {
	case ',':
	case '.':
	case ' ':
	case '!':
	case '?':
	case ':':
	case ';':
		elem = '_';
	}

	if (checkLengthOfList()) {
		dataList.push_back(elem);
	}
	else {
		this->uploadToFile();
		dataList.clear();
		dataList.push_back(elem);
	}
}

inline void DataManager<char>::push(char elems[], int size) {
	for (int i = 0; i < size; i++)
		this->push(elems[i]);
}

inline char DataManager<char>::peek() {
	if (dataList.size() < 2)
	{
		return 0;
	}
	else
	{
		return dataList.at(1);//возвращаем второй элемент
	}
}

inline char DataManager<char>::pop() {
	if (dataList.size() == 0)
	{
		this->downloadFromFile();
	}

	char copy = dataList.at(dataList.size() - 1);
	dataList.pop_back();

	if (dataList.size() == 0)
	{
		this->downloadFromFile();
	}
	return copy;
}


inline char DataManager<char>::popUpper() {
	if (dataList.size() == 0)
	{
		this->downloadFromFile();
	}
	char copy = dataList.at(dataList.size()-1);
	if (dataList.size() == 0)
	{
		this->downloadFromFile();
	}
	copy = toupper(copy);
	dataList.pop_back();

	return copy;
}

inline char DataManager<char>::popLower() {
	if (dataList.size() == 0)
	{
		this->downloadFromFile();
	}
	char copy = dataList.at(0);
	dataList.erase(dataList.begin());
	if (dataList.size() == 0)
	{
		this->downloadFromFile();
	}
	copy = tolower(copy);
	return copy;
}

inline bool DataManager<char>::checkLengthOfList() {
	if (dataList.size() < 64) return true;
	else return false;
}

inline void DataManager<char>::print() {
	for (int i = 0; i < dataList.size(); i++) {
		cout << dataList[i] << "\t";
	}
	cout << "\n" << endl;
}

inline void DataManager<char>::uploadToFile() {
	std::ofstream f2out("dump.dat", std::ios_base::out);
	for (int i = 0; i < dataList.size(); i++) {
		f2out << dataList[i];
	}
	f2out.close();
}

inline void DataManager<char>::downloadFromFile() {
	std::ifstream F("dump.dat", std::ios_base::in);
	if (F.is_open()) {
		std::string str;
		std::getline(F, str);

		std::string typeName = typeid(char).name();

		while (str.compare("")) {
			if (typeName == "int") {
				this->push(std::stoi(str));
			}

			if (typeName == "double") {
				this->push(std::stod(str));
			}

			if (typeName == "char") {
				this->push(*(str.c_str()));
			}
			std::getline(F, str);
		}
		printf("DataManager's data loaded successfully.\n");
	}
	else {
		printf("Can't open file. DataManager is empty.\n");
	}
}