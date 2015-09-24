//
//  HeadSort.hpp
//  SortTest
//
//  Created by 王曙光 on 22/9/15.
//  Copyright © 2015 Alex. All rights reserved.
//

#ifndef HeadSort_h
#define HeadSort_h

#include <stdio.h>
#include "Sort.h"
#include <stdint.h>
#include <string>


using namespace std;

struct CHeap_node{
    int value;
};

class CHeapSort:public CSort {
public:
    CHeapSort();
    CHeapSort(int32_t max_size);
    ~CHeapSort();
    virtual void Sort(int* arr, const int size){}
    bool max_HeapPify(int i);
    bool build_Max_Heap();
    void heapSort();
    bool setArrayValue(int i,int value);
    bool insertArrayValue(int value);
    bool scanFromFile(string file_name);
    void setMaxSize(int32_t size);
    void display();
    int getLeft(int i){return i*2;}
    int getRight(int i){return i*2 + 1;}
private:
    int32_t max_size = 1000;
    CHeap_node* arr;
    int arr_length, heap_size;
};



#endif /* HeadSort_hpp */
