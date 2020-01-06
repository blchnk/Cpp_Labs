#pragma once
#include <string>

using namespace std;

class Book 
{
private:
	string name_;
	string author_;
	int year_;
public:
	Book(string name, string author, int year);
	string getName() const;
	string getAuthor() const;
	int getYear() const;
};

class BookSorter 
{
public:
	bool operator() (Book* b1, Book* b2);//предикат
};

class BookFinder 
{
public:
	bool operator() (Book* book);
};
