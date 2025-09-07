#pragma once
#include <array>
#include <cstdio>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <ostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

namespace my_print {

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> p) {
  os << "{" << p.first << "," << p.second << "}";
  return os;
}

// 打印容器内容
template <typename T>
void print(const T& container) {
  if (container.empty()) {
    std::cout << "{}" << std::endl;
  } else {
    std::cout << "{";
    auto begin = container.begin();
    std::cout << *begin;
    begin++;
    std::for_each(begin, container.end(), [](const typename T::value_type& i) {
      std::cout << "," << i;
    });
    std::cout << "}" << std::endl;
  }
}


inline void Test() {
  {
    std::cout << "empty" << std::endl;
    std::vector<int> v{};
    std::deque<int> d{};
    std::array<int, 0> arr{};
    std::list<int> lst{};
    std::forward_list<int> flst{};

    std::map<int, int> m{};
    std::multimap<int, int> mm{};
    std::set<int> s{};
    std::multiset<int> ms{};

    std::unordered_map<int, int> um{};
    std::unordered_multimap<int, int> umm{};
    std::unordered_set<int> us{};
    std::unordered_multiset<int> ums{};


    print(v);
    print(d);
    print(arr);
    print(lst);
    print(flst);
    print(m);
    print(mm);
    print(s);
    print(ms);
    print(um);
    print(umm);
    print(us);
    print(ums);
  }
  {
    std::cout << "non empty" << std::endl;
    std::vector<int> v{1, 2, 3};
    std::deque<int> d{1, 2, 3};
    std::array<int, 3> arr{1, 2, 3};
    std::list<int> lst{1, 2, 3};
    std::forward_list<int> flst{1, 2, 3};

    std::map<int, int> m{{1, 2}, {2, 3}, {3, 4}};
    std::multimap<int, int> mm{{1, 2}, {2, 3}, {3, 4}};
    std::set<int> s{1, 2, 3};
    std::multiset<int> ms{1, 2, 3};

    std::unordered_map<int, int> um{{1, 2}, {2, 3}, {3, 4}};
    std::unordered_multimap<int, int> umm{{1, 2}, {2, 3}, {3, 4}};
    std::unordered_set<int> us{1, 2, 3};
    std::unordered_multiset<int> ums{1, 2, 3};

    print(v);
    print(d);
    print(arr);
    print(lst);
    print(flst);
    print(m);

    print(mm);
    print(s);
    print(ms);
    print(um);
    print(umm);
    print(us);
    print(ums);
  }
  std::cout << "test over!" << std::endl;
}

}  // namespace my_print
