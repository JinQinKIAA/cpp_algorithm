#pragma once
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string.h>
#include <time.h>
#include <vector>



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


  inline int remove_element(int arr[], int size, int val){
    int * p  = arr;
    int *q = arr+size-1;
    int new_size=size;

    while(p < q){
        while (p < q && *p != val) {
            p++;
        }

        while (p < q && *q == val) {
            q--;
            new_size--;
        }
        if (p < q) {
            // int temp = *p;
            // *p = *q;
            // *q = temp;
            *p = *q;
            p++;
            q--;
            new_size--;
        }
    }
    return new_size;
  }

  inline  int removeElement(std::vector<int>& nums, int val) {
        auto p = nums.begin();
        auto q = nums.end()-1;
        // int ret_size = static_cast<int>(nums.size());
        int ret_size = nums.size();

        while(p<=q){
            while(p<=q && *p !=val){
                p++;
            }
            while(p<=q && *q==val){
                q--;
                ret_size--;
            }
            if(p<=q){
                *p=*q;
                p++;
                q--;
                ret_size--;
            }
        }
        return ret_size;
    }

inline int remove_element_official(std::vector<int> & v, int val){
    int n = static_cast<int>(v.size());
    // std::cout << "size:"<<  n << std::endl;
    int left = 0;
    for (int right = 0; right < n; right++) {
        if (v[right]!=val) {
            v[left] = v[right];
            // std::cout << "o:"<<  left << std::endl;
            left++;
        }
    }
    return left;
}


    inline void test(){
        // char str[] = "helloo world";
        // reverse(str,strlen(str));
        // std::cout << str << std::endl;


        // srand(time(0));
        // int arr[10];
        // for(int i = 0; i < 10; i++){
        //     arr[i] = rand()%100;
        // }
        // even_left_odd_right(arr,10);
        // even_left_odd_right_2(arr,10);
        // even_left_odd_right_3(arr,10);

        // for(int i = 0; i < 10; i++){
            // std::cout << arr[i] << std::endl;
        // }


        int arr[10]={1,2,3,4,3,3,7,8,9,3};
        int new_size = remove_element(arr, 10, 3);
        for(int i = 0; i < new_size; i++){
            std::cout << arr[i] << std::endl;
        }

        std::cout << "new size: " << new_size << std::endl;
        std::vector<int>v{1,2,3,4,3,3,7,8,9,3};
        // int ret_size = removeElement(v, 3);
        int ret_size = remove_element_official(v, 3);
        std::cout << "new size: " << ret_size << std::endl;
        for(int i = 0; i < ret_size; i++){
            std::cout << arr[i] << std::endl;
        }


    };
}