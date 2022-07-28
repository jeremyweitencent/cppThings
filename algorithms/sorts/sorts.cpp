//
// Created by bytedance on 2022/7/28.
//

#include "sorts.h"
#include <iostream>
#include <ctime>

using namespace std;

int random(int low, int high) {
    return low + rand() % (high - low + 1);
}

static void prepareData(int array[], int length) {
    srand(time(NULL));
    for (int i=0; i<length; i++) {
        array[i] = random(0, 100);
    }
}

static void printData(int *array, int length) {
    for (int i=0; i<length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void sorts::insert_sorts() {
    cout << "insert_sorts_invoked." << endl;
    int data[10]{};
    prepareData(data, sizeof(data) / sizeof(int));
    printData(data, sizeof(data) / sizeof(int));
}


