﻿#include <iostream>
#include <vector>
#include <algorithm>

#include "Book.h"

using namespace std;

int main()
{
    std::cout << "TASK 3-4\n";
    setlocale(LC_ALL, "RUSSIAN");

    vector<Book*> books;

    books.push_back(new Book("Война и мир", "Толстой Л.Н.", 2010));
    books.push_back(new Book("Подросток", "Достоевский Ф.М.", 2004));
    books.push_back(new Book("Обрыв", "Гончаров И.А.", 2010));
    books.push_back(new Book("Анна Каренина", "Толстой Л.Н.", 1999));
    books.push_back(new Book("Обыкновенная история", "Гончаров И.А.", 2011));
    books.push_back(new Book("Утраченные иллюзии", "Бальзак О.", 2009));
    books.push_back(new Book("Оливер Твист", "Диккенс Ч.", 2001));
    books.push_back(new Book("Фауст", "Гёте И.В.", 2010));
    books.push_back(new Book("Лилия долины", "Бальзак О.", 1998));

    cout << "\nКниги в алфавитном порядке:\n\n";
    BookSorter book_sorter;

    sort(books.begin(), books.end(), book_sorter);
    vector<Book*>::iterator i;
    for (i = books.begin(); i != books.end(); ++i)
    {
        cout << (*i)->getAuthor() << " \"" << (*i)->getName() << "\"" << endl;
    }

    
    BookFinder book_finder;
    vector<Book*>::iterator finder = find_if(books.begin(), books.end(), book_finder);


    cout << "\nКниги в диапазоне года издания 2009 - 2019:\n\n";
    while (finder != books.end())
    {
    cout << (*finder)->getAuthor() << " \""
        << (*finder)->getName() << "\"" << std::endl;
    finder = find_if(++finder, books.end(), book_finder);
    }
    for (i = books.begin(); i != books.end(); ++i)
    {
        delete (*i);
    } 
}