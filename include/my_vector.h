#pragma once
#include <initializer_list>
#include <iostream>
#include <my_io.h>

namespace my_vector {

class Array{
public:
    Array(int size = 10): cap(size), cur(0){
        p = new int[cap]();
    };
    Array(std::initializer_list<int> il){
        cur = il.size();
        cap = cur;
        p = new int[cap]();
        for (auto & item : il ) {
            *p=item;
            p++;
        }
        p-=cur;
    }

    ~Array(){
        delete [] p;
        p = nullptr;
    };

public:
    void push_back(int val){
        if (cur < cap) {
            *(p+cur) = val;
            cur++;
        }else{
            expand(2*cap);
            *(p+cur) = val;
            cur++;
        }
    };
    void pop_back(){
        cur--;
    };
    void insert(int pos, int val){
        if (pos < 0 || pos > cur){
            return;
        }
        if (cur < cap) {
            for (auto i = cur-1; i >= pos; i--) {
                *(p+i+1) = *(p+i);
            }
            *(p+pos) = val;
            cur++;
        }else {
            expand(2*cap);
            for (auto i = cur-1; i >= pos; i--) {
                *(p+i+1) = *(p+i);
            }
            *(p+pos) = val;
            cur++;
        }
    };
    void erase(int pos){
        if (pos < 0 || pos >= cur) {
            return;
        }
        for (int i = pos;i<cur;i++){
            p[i]=p[i+1];
        }
        cur--;
    };
    int find(int val){
        for (int i = 0; i < cur; i++) {
            if (p[i]==val) {
                return i;
            }
        }
        return -1;
    };

    void debug(){
        std::cout << "cap " << cap << std::endl;
        std::cout << "cur " << cur << std::endl;
        std::cout << "{";
        for (auto i =0; i< cur-1; i++) {
            std::cout << *(p+i) << ",";
        }
        std::cout << *(p+cur-1) << "}" << std::endl;
    }
private:
    void expand(int size){
        auto ptemp = new int[size](); 
        for(auto i=0; i < cap; i++){
            *(ptemp+i) = *(p+i);
        }
        delete [] p;
        p = ptemp;
        ptemp = nullptr;
        cap = size;
    }



private:
    int *p; // pointer
    int cap; // capacity
    int cur; // current data number   

};


inline void test(){
    // Array a{};
    // for (auto i = 0; i<10; i++) {
    //     a.push_back(1);
    // }
    // a.push_back(2);
    // a.debug();


    Array a{1,2,3};
    a.insert(0, 999);
    a.debug();
    a.insert(3, 999);
    a.insert(5, 444);
    a.insert(6, 666);
    a.insert(10, 666);
    a.debug();
    a.erase(0);
    a.debug();
    a.erase(2);
    a.debug();
    a.erase(10);
    a.debug();
    a.erase(4);
    a.debug();
    a.pop_back();
    a.debug();
    std::cout << a.find(1) << std::endl;
    std::cout << a.find(2) << std::endl;
    std::cout << a.find(3) << std::endl;
    std::cout << a.find(4) << std::endl;
    a.insert(3, 10);
    a.debug();
}

}

