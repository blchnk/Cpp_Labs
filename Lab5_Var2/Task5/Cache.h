#pragma once

#include <string>
#include <vector>

using namespace std;

template<typename T>
class Cache 
{
public:
	void put(T elem);
	void operator+= (T elem);
	bool contains(T elem);
	void print();
private:
	vector<T> data;
};

template <typename T>
void Cache<T>::put(T elem) {
	data.push_back(elem);
}

template <typename T>
void Cache<T>::operator+= (T elem) {
	data.push_back(elem);
}

template <typename T>
bool Cache<T>::contains(T elem) {
	for (int i = 0; i < data.size(); i++) {
		if (data.at(i) == elem)
			return true;
	} return false;
}

template <typename T>
void Cache<T>::print() {
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << endl; 
	}
	cout << "\n" << endl;
}


template<>
class Cache<string> 
{
public:
	void put(string str);
	void add();
	bool contains(string str);
private:
	vector<string> data;
};

void Cache<string>::put(string str) {
	data.push_back(str);
}

void Cache<string>::add() {
	if (data.size() > 100) {
		cout << "Elements more then 100. Lovi maslinu." << endl;
		throw 1;
	}
}

bool Cache<string>::contains(string str) {
	const char* cur = str.c_str();
	for (int i = 0; i < data.size(); i++) {
		const char* temp = data[i].c_str();

		if (temp[0] == cur[0]) return true;
	} return false;
}