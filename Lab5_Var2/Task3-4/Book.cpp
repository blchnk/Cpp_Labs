#include <string>
#include "Book.h"

using namespace std;

Book::Book(string name, string author, int year) {
	name_ = name;
	author_ = author;
	year_ = year;
}

string Book::getName() const {
	return name_;
}

string Book::getAuthor() const {
	return author_;
}

int Book::getYear() const {
	return year_;
}

bool BookSorter::operator() (Book* b1, Book* b2) {
	return b1->getAuthor() < b2->getAuthor();
}

bool BookFinder::operator() (Book* book) {
	return (book->getYear() > 2009);
}