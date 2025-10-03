#pragma once

#include <iostream>
namespace my_list {

class Node {
public:
  Node(int data = 111) : data(data), next(nullptr) {}

  int data;
  Node *next;
};

class MyList {
  public:
    MyList() { head = new Node(); }
    ~MyList() {
        // std::cout << "deconstructor" << std::endl;
        Node*p = head;
        while (p!=nullptr) {
            head = head->next;
            // std::cout << p->data << std::endl;
            delete p;
            p = head;
        }
    }

    void push_back(int val){
        Node * p = head;
        while (p->next!=nullptr) {
            p=p->next;
        }
        p-> next = new Node(val);
    }

    void push_front (const int val){
        // Node * p = new Node();
        // head->data = val;
        // p->next = head;
        // head = p;
        // p = nullptr;
        Node * p = new Node(val);
        p->next = head->next;
        head->next = p;
        p = nullptr;
    }


    void remove_first(const int val){
        Node * p = head->next;
        Node * pre = head;
        while ( p!=nullptr && p->data != val) {
            pre = pre->next;
            p = p->next;
        }
        if (p!=nullptr) {
            pre->next = p->next;
            delete p;
        }
    }

    void remove(const int val){
        Node * p = head->next;
        Node * pre = head;

        while ( p!=nullptr) {
            if (p->data == val) {
                pre->next = p->next;
                delete p;
                p = pre->next;
            }else{
                pre = pre->next;
                p = p->next;
            }
        }
    }

    void print(){
        Node * p = head->next;
        while (p != nullptr) {
            std::cout << p->data << std::endl;
            p = p->next;
        }
    }

    bool find(int val){ // O(n) 根数组的查找时间复杂度一致
        Node *p = head->next;
        while (p != nullptr) {
            if (p->data == val) {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    void reverse(){
        if (head->next!=nullptr && head->next->next != nullptr) {
            std::cout << "test reverse" << std::endl;
            Node * o = head->next;
            Node * p = head->next->next;
            Node * q = head->next->next->next;
            o->next = nullptr;
            while (q!=nullptr) {
                // std::cout << p->data << std::endl;
                p->next = o;
                o=p;
                p=q;
                q=q->next;
            }
            p->next = o;
            head->next = p;
        }
        
    }


    void reverse_push_front(){ //头插法
        if (head->next!=nullptr && head->next->next != nullptr) {
            Node *p = head->next;
            Node *tmp = p;
            head->next = nullptr;
            while (p!=nullptr) {
                tmp = p->next;
                p->next = head->next;
                head->next = p;
                p = tmp;
            }
        }
    }

    int find_kth_inverse(int k){
        if (k <=0) {
            std::cout << "k must be positive" << std::endl;
            return -1;
        }
        Node * p = head;
        Node * q = head;
        for (int i = 0; i < k; i++) {
            if (p == nullptr) {
                std::cout << "inverse kth does not exist!"  << std::endl;
                return -1;
            }
            p = p->next;
        }
        while (p!=nullptr) {
            p = p->next;
            q = q->next;
        }
        return q->data;
    }


private:
  Node *head;
};

inline void test() {
    MyList list{};
    list.push_back(0);
    list.push_back(1);
    list.push_front(999);
    list.push_back(2);
    list.push_back(3);
    list.push_front(999);
    list.push_front(999);
    // list.print();
    list.remove(999);
    list.print();
    // std::cout  << list.find(33) << std::endl;
    
    std::cout  << "---test reverse---" << std::endl;
    // list.reverse();
    list.reverse_push_front();
    list.print();
    std::cout << "the 3th inverse is" << std::endl;
    std::cout << list.find_kth_inverse(3) << std::endl;

}

} // namespace my_list