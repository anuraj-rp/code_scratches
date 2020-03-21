//
// Created by ARajendraprakash on 21-Mar-20.
//

#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>

#include "dllTemplated.h"

using namespace std;

int main()
{
    std::random_device rd;//use to get seed for engine
    srand(time(NULL));
    std::mt19937 gen(rand());
    std::uniform_int_distribution<> dis(1, 2000);

    dis.reset();
    std::vector<int> v;

    DLList<int> intList;
    DLList<float> floatList;

    std::cout << "Random numbers\n";
    for(int n=0; n<100; ++n)
    {
        int r = dis(gen);
        intList.addFront(r);
    }

    intList.printList();
    cout << endl;
    std::cout << "Sorted numbers\n";
    intList.sortList(intList.getHead(), intList.getHead(), intList.getFront());
    intList.printList();

    std::cout << "\n";
    return 0;
}