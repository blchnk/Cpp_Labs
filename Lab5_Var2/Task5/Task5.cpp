#include <iostream>
#include "Cache.h"

using namespace std;

int main()
{
    std::cout << "TASK 5\n";

    Cache<int> cache;
    cache.put(1);   // так должно работать
    cache.put(2);
    cache.put(3);
    cache += 5;     // так тоже должно работать
    cache.print();

    Cache<std::string> voc;
    voc.put("OK");
    cout << voc.contains("Only") << endl; // 1
    cout << cache.contains(5) << endl;    // 1
    return 0;
}