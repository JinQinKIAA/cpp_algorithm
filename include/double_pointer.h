#pragma once
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string.h>
#include <time.h>



namespace double_pointer {




inline  void reverse(char arr [], int size){
    auto p = arr;
    auto q = p+size-1;
    // std::cout <<*p << std::endl;
    // std::cout << static_cast<void *>(p) << std::endl;
    // std::cout << static_cast<void *>(q) << std::endl;
    // std::cout <<*q << std::endl;
    // if (p > q) {
    //     std::cout << "p > q" << std::endl;
    // }else {
    //     std::cout << "p < q" << std::endl;
    // }

    // while (p <= q) {
    while (p < q) {
        int temp;
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }

  }


  inline void even_left_odd_right(int arr [], int size){
    int * left = arr;
    int * right = arr+size-1;
    // std::cout <<*left  << std::endl;
    // std::cout <<*right  << std::endl;
    while (left < right) {
        if (*left % 2 == 0 && *right %2 == 0) {
            left++;
        }
        else if (*left % 2 == 0 && *right %2 == 1) {
            left++;
            right--;
        }
        else if (*left % 2 == 1 && *right %2 == 0) {
            int temp = *left;
            *left = * right;
            *right = temp;
            left++;
            right--;
        }
        else if (*left % 2 == 1 && *right %2 == 1) {
            right--;
        }
    }
  }

  inline void even_left_odd_right_2(int arr [], int size){
    int * p = arr;
    int * q = arr+size-1;
    while (p < q) {
        if ((*p & 0x1) == 0) {
            p++;
            continue;
        }
        if ((*q & 0x1) == 1) {
            q--;
            continue;
        }
        int temp = *p;
        *p = * q;
        *q = temp;
        p++;
        q--;
    }
  }

  inline void even_left_odd_right_3(int arr [], int size){
    int *p = arr;
    int *q = arr+size-1;

    while (p < q) {
        while ( p < q && (*p & 0x1) == 0) {
            p++;
        }
        while ( p < q && (*q & 0x1) == 1) {
            q--;
        }

        if (p < q) {
            int temp  = *q;
            *q = *p ;
            *p = temp;
            p++;
            q--;
        }

    }

    
  }

    inline void test(){
        // char str[] = "helloo world";
        // reverse(str,strlen(str));
        // std::cout << str << std::endl;


        srand(time(0));
        int arr[10];
        for(int i = 0; i < 10; i++){
            arr[i] = rand()%100;
        }
        // even_left_odd_right(arr,10);
        // even_left_odd_right_2(arr,10);
        even_left_odd_right_3(arr,10);
        for(int i = 0; i < 10; i++){
            std::cout << arr[i] << std::endl;
        }


    };
}