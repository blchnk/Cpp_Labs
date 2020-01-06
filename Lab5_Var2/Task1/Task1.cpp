#include <iostream>
#include "DataManager.h"

int main()
{
    std::cout << "TASK 1\n";

    DataManager<int> manager;
    manager.push(-9);
    manager.print();

    int a[60] = { 0 };
    manager.push(a, 60); // уже в наборе 61 элемент
    manager.print();

    int x = manager.peek(); // узнаем последний элемент (без извлечения)
    manager.print();

    for (int i = 1; i < 15; ++i)
    {
        manager.push(i); // здесь на четвертой итерации должна произойти выгрузка 64 элементов в файл dump.dat
    } 
    x = manager.pop(); // сейчас в наборе 11 элементов
    
    DataManager<char> char_manager; // явная специализация шаблона для char
    char_manager.push('h');
    char_manager.push('e');
    char_manager.push('l');
    char_manager.push('l');
    char_manager.push('o');
    char_manager.print();

    char ch = char_manager.popUpper(); // этот метод есть только для char
    std::cout << ch << std::endl;
    
}
