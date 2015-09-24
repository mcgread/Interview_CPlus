//
//  HeadSort.cpp
//  SortTest
//
//  Created by 王曙光 on 22/9/15.
//  Copyright © 2015 Alex. All rights reserved.
//

#include "HeadSort.h"
#include <iostream>

using namespace std;

//
//class CHeap_node{
//    int value;
//};
//
//class CHeapSort:public CSort {
//public:
//    CHeapSort();
//    CHeapSort(int_32 max_size);
//    ~CHeapSort();
//    virtual void Sort(int* arr, const int size){};
//    bool max_HeapPify(int i);
//    bool build_Max_Heap();
//    void heapSort();
//    void setArrayValue(int i,int value);
//    bool insertArrayValue(int value);
//    void display();
//    bool scanFromFile(string file_name);
//    void setMaxSize(int32_t size);
//private:
//    int32_t max_size = 1000;
//    CHeap_node* arr;
//    int arr_length;
//
//    
//};



CHeapSort::CHeapSort(){
    if (max_size == 1000) {
        cout << "use setMaxSize to set the size of the array(Default 1000)" << endl;
    }else cout << "use custom max_size : "<< max_size << endl;
    try {
        this->arr = new CHeap_node[max_size];
        arr_length = 0; heap_size = 0;
    } catch (const std::bad_alloc &e) {
        std::cerr << "new array node pool error" << std::endl;
    }
}

CHeapSort::CHeapSort(int32_t max_size){
    this->max_size = max_size;
    CHeapSort();
}

CHeapSort::~CHeapSort(){
    delete[] this->arr;
}

bool CHeapSort::max_HeapPify(int i){
    int left = getLeft(i);
    int right = getRight(i);
    int largest = i;
    if (left <= heap_size && arr[left].value > arr[i].value) {
        largest = left;
    }else
        largest = i;
    if (right <= heap_size && arr[right].value > arr[largest].value) {
        largest = right;
    }
    CHeap_node temp_node;
    if (largest != i) {
        temp_node = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp_node;
        max_HeapPify(largest);
    }
    return true;
}

bool CHeapSort::build_Max_Heap(){
    int pify_location = arr_length/2;
    for (; pify_location > 0; pify_location--) {
        max_HeapPify(pify_location);
    }
    return true;
}
bool CHeapSort::insertArrayValue(int value){
    if (arr_length < max_size) {
        arr[++arr_length].value = value;
        heap_size++;
    }
    else{
        cout << "overflow max_size" << endl;
        return false;
    }
    return true;
}

bool CHeapSort::setArrayValue(int i , int value){
    if (i <= heap_size) {
        arr[i].value = value;
    }
    return true;
}

void CHeapSort::heapSort(){
    CHeap_node temp;
    if (!arr_length) return;
    build_Max_Heap();
    for (int i = arr_length; i > 1; i--) {
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        heap_size--;
        max_HeapPify(1);
    }
}

//其实这个是没有用的
void CHeapSort::setMaxSize(int32_t size){
    this->max_size = size;
}


bool scanFromFile(string file_name){
    return true;
}


void CHeapSort::display(){
    for (int i = 1; i <= arr_length; i++) {
        cout <<"the " << i << " number is"<< arr[i].value << endl;
    }
}






















