//
//  main.cpp
//  SortTest
//
//  Created by 王曙光 on 23/8/15.
//  Copyright (c) 2015 Alex. All rights reserved.
//

#include <iostream>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "InsertSort.h"
#include "HeadSort.h"
#include <vector>


#define LENGTH 100
#define DEBUG(cond,freq) if(IS_DEBUG) cout << "Debug Message:[ "\
<< #cond << " = " << cond << ", " << freq << " ]" << endl;

bool IS_DEBUG = true;
using namespace std;


int main(int argc, const char * argv[]) {
    int arr[LENGTH];
    for(int i = 0; i < LENGTH; i++){
        arr[i] = rand()%1000;
    }
//    CBubbleSort bs;
//    CQuickSort qs;
//    CInsertSort is;
//  bs.Sort(arr, LENGTH);
//  qs.quickSort(arr,0,LENGTH-1);
    
//    is.shellInsertSort(arr, LENGTH);
//    DEBUG(arr, "in the main")
//    for(int i = 0; i < LENGTH; i++){
//        cout << arr[i] <<endl;
//    }
    
    CHeapSort hs;
    hs.insertArrayValue(1);
    hs.insertArrayValue(100);
    hs.insertArrayValue(3);
    hs.insertArrayValue(23);
    hs.insertArrayValue(5);
    hs.insertArrayValue(17);
    hs.display();
    hs.heapSort();
    hs.display();
    
    
    
    
    return 0;
}
