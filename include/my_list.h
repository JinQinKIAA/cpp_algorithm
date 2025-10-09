#pragma once

#include <cerrno>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <regex>
#include <system_error>
#include <vector>
#include <unordered_map>


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

    friend MyList & merge_2_list(MyList &list1, MyList &list2);
    friend Node * find_loop_and_return(MyList & list);

private:
  Node *head;
};


// inline MyList & merge_2_list(MyList & list1, MyList & list2){
//     // 比较笨的办法
//     Node * p_pre= list1.head;
//     Node * p = list1.head->next;
//     Node * q = list2.head->next;
//     Node * q_tmp = list2.head->next;

//     while (p != nullptr && q != nullptr) {
//         if (p->data >= q->data) {
//             p_pre->next = q;
//             q_tmp = q->next;
//             q->next = p;
//             q = q_tmp;
//             p_pre = p_pre->next;

//         }else {
//             p_pre = p_pre->next;
//             p = p->next;
//         }        
//     }
//     if (p == nullptr) {
//         p_pre->next = q;
//     }
//     return  list1;
// }

inline MyList & merge_2_list(MyList & list1, MyList & list2){
    Node * last = list1.head;
    Node * p = list1.head->next;
    Node * q = list2.head->next;

    while (p != nullptr && q != nullptr) {
        if (p->data <= q->data) {
            last->next = p;
            last = last->next;
            p = p->next;
        }else {
            last->next = q;
            last = last->next;
            q = q->next;
        }
    }

    if (p == nullptr) {
        last->next = q;
    }else {
        last->next = p;
    }

    return  list1;
}

// inline class Aux{
//     public:
//         std::map<Node *, std::vector<int>>;
// };

// inline Node* find_loop_and_return(MyList & list){
//     auto aux = std::map<Node *, std::vector<int>>{};
//     Node* p = list.head;
//     while (p!=nullptr && aux[p].size()<1) {
//         aux[p].push_back(0);
//         p = p->next;
//     }
//     if (p == nullptr){
//         std::cout << "no loop" << std::endl;
//         return nullptr; 
//     }else {
//         std::cout << "find loop" << std::endl;
//         return p;
//     }
// }
inline Node* find_loop_and_return(Node *head){
    auto aux = std::unordered_map<Node *, std::vector<int>>{};
    Node* p = head;
    while (p!=nullptr && aux[p].size()<1) {
        aux[p].push_back(0);
        p = p->next;
    }
    if (p == nullptr){
        std::cout << "no loop" << std::endl;
        return nullptr; 
    }else {
        std::cout << "find loop" << std::endl;
        return p;
    }
}

inline Node* find_loop_and_return_local(Node *head){
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return nullptr;
    }

    Node *p = head;
    Node *q = head;

    while (q!=nullptr && q->next!=nullptr) {
        p = p->next;
        q = q->next->next;

        if (p==q) {
            break;
        }
    }

    if (q == nullptr) {
        std::cout << "no loop" << std::endl;
        return nullptr;
    }else{
        std::cout << "find loop" << std::endl;
        p = head;

        while (p!=q) {
            p = p->next;
            q = q->next;
        }
    }
    return p;
}


inline Node * if_two_list_merge(Node* head1, Node * head2){
    int count1 = 0;
    int count2 = 0;
    auto p1 = head1;
    auto p2 = head2;

    while (p1!=nullptr) {
        count1++;
        p1=p1->next;
    }

    while (p2!=nullptr) {
        count2++;
        p2=p2->next;
    }

    int s = 0;
    p1 = head1;
    p2 = head2;
    if (count1 >= count2 ) {
        s = count1-count2;
        while (s-->0) {
            p1 = p1->next;
        }
    }else {
        s = count2 - count1;
        while (s-->0) {
            p2 = p2->next;
        }
    }
    while (p1!=nullptr && p2!=nullptr) {
        if (p1==p2) {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return nullptr;
}


inline void test() {
    // MyList list{};
    // list.push_back(0);
    // list.push_back(1);
    // list.push_front(999);
    // list.push_back(2);
    // list.push_back(3);
    // list.push_front(999);
    // list.push_front(999);
    // // list.print();
    // list.remove(999);
    // list.print();
    // // std::cout  << list.find(33) << std::endl;
    
    // std::cout  << "---test reverse---" << std::endl;
    // // list.reverse();
    // list.reverse_push_front();
    // list.print();
    // std::cout << "the 3th inverse is" << std::endl;
    // std::cout << list.find_kth_inverse(3) << std::endl;


    // merge 2 list
    // MyList list1{};
    // MyList list2{};
    // list1.push_back(1);
    // list1.push_back(5);
    // list1.push_back(10);
    // list2.push_back(2);
    // list2.push_back(3);
    // list2.push_back(11);
    // list1.print();
    // list2.print();
    // auto merged = merge_2_list(list1, list2);
    // merged.print();

    // // find loop
    // Node *head = new Node(0);
    // Node *n0 = new Node(0);
    // Node *n1 = new Node(1);
    // Node *n2 = new Node(2);
    // Node *n3 = new Node(3);

    // head->next = n0;
    // n0->next = n1;
    // n1->next =n2;
    // n2->next = n3;
    // n3->next=n2;

    // // auto p = find_loop_and_return(head);
    // auto p = find_loop_and_return_local(head);
    // std::cout << p->data << std::endl;


    // if two list merge
    Node *head1 = new Node(0);
    Node *head2 = new Node(0);

    Node *n0 = new Node(0);
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    head1->next = n0;
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;

    head2->next = n4;
    n4->next = n2;

    auto p = if_two_list_merge(head1, head2);
    std::cout << p->data << std::endl;

}

} // namespace my_list