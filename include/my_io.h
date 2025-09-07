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

template <class T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& v) {
  if (v.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    for (auto it = v.begin(); it != --v.end(); ++it) {
      os << *it << ",";
    }
    os << v.back() << "}" ;
  }
  return os;
}

template <typename T, std::size_t size>
std::ostream& operator<<(std::ostream& os, const std::array<T, size>& arr) {
  if (arr.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    for (auto it = arr.begin(); it != arr.end() - 1;
         ++it) {  // array 迭代器 v.begin() v.end() 不支持 ++，-- 操作
                  // 因此只可以用 +1 -1 或者保存给另外的迭代器
      os << *it << ",";
    }
    os << arr.back() << "}" ;
  }
  return os;
}
template <class T>
std::ostream& operator<<(std::ostream& os, std::deque<T> d) {
  if (d.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    for (auto it = d.begin(); it != --d.end(); ++it) {
      os << *it << ",";
    }
    os << d.back() << "}" ;
  }
  return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& lst) {
  if (lst.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    for (auto it = lst.begin(); it != --lst.end(); ++it) {
      os << *it << ",";
    }
    os << lst.back() << "}" ;
  }
  return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, std::forward_list<T> flst) {
  if (flst.empty()) {
    os << "{}" ;
  } else {
    auto curr = flst.begin();
    auto next = flst.begin();
    ++next;
    os << "{";
    for (; next != flst.end(); ++next) {
      os << *curr << ",";
      ++curr;
    }
    os << *curr << "}" ;
  }
  return os;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, std::map<K, V> m) {
  if (m.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    for (auto it = m.begin(); it != --m.end(); ++it) {
      os << "{" << it->first << "," << it->second << "}"
         << ",";
    }
    os << "{" << (--m.end())->first << "," << (--m.end())->second << "}"
       << "}" ;
  }
  return os;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, std::multimap<K, V> m) {
  if (m.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    for (auto it = m.begin(); it != --m.end(); ++it) {
      os << "{" << it->first << "," << it->second << "}"
         << ",";
    }
    os << "{" << (--m.end())->first << "," << (--m.end())->second << "}"
       << "}" ;
  }
  return os;
}

template <typename K>
std::ostream& operator<<(std::ostream& os, const std::set<K> s) {
  if (s.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    for (auto it = s.begin(); it != --s.end(); ++it) {
      os << *it << ",";
    }
    os << *(--s.end()) << "}" ;
  }
  return os;
}

template <typename K>
std::ostream& operator<<(std::ostream& os, const std::multiset<K> s) {
  if (s.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    for (auto it = s.begin(); it != --s.end(); ++it) {
      os << *it << ",";
    }
    os << *(--s.end()) << "}" ;
  }
  return os;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, std::unordered_map<K, V> m) {
  if (m.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    auto preEnd = m.begin();
    for (auto it = m.begin(); it != m.end(); ++it) {
      preEnd = it;
    }
    for (auto it = m.begin(); it != preEnd; ++it) {
      os << "{" << it->first << "," << it->second << "}"
         << ",";
    }
    os << "{" << preEnd->first << "," << preEnd->second << "}"
       << "}" ;
  }
  return os;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, std::unordered_multimap<K, V> m) {
  if (m.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    auto preEnd = m.begin();
    for (auto it = m.begin(); it != m.end(); ++it) {
      preEnd = it;
    }
    for (auto it = m.begin(); it != preEnd; ++it) {
      os << "{" << it->first << "," << it->second << "}"
         << ",";
    }
    os << "{" << preEnd->first << "," << preEnd->second << "}"
       << "}" ;
  }

  return os;
}

template <typename K>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<K> s) {
  if (s.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    auto preEnd = s.begin();
    for (auto it = s.begin(); it != s.end(); ++it) {
      preEnd = it;
    }
    for (auto it = s.begin(); it != preEnd; ++it) {
      os << *it << ",";
    }
    os << *preEnd << "}" ;
  }
  return os;
}

template <typename K>
std::ostream& operator<<(std::ostream& os, const std::unordered_multiset<K> s) {
  if (s.empty()) {
    os << "{}" ;
  } else {
    os << "{";
    auto preEnd = s.begin();
    for (auto it = s.begin(); it != s.end(); ++it) {
      preEnd = it;
    }
    for (auto it = s.begin(); it != preEnd; ++it) {
      os << *it << ",";
    }
    os << *preEnd << "}" ;
  }
  return os;
}

namespace my_os {

inline void test() {
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

    std::cout << v << std::endl;
    std::cout << d << std::endl;
    std::cout << arr << std::endl;
    std::cout << lst << std::endl;
    std::cout << flst << std::endl;
    std::cout << m << std::endl;
    std::cout << mm << std::endl;
    std::cout << s << std::endl;
    std::cout << ms << std::endl;
    std::cout << um << std::endl;
    std::cout << umm << std::endl;
    std::cout << us << std::endl;
    std::cout << ums << std::endl;
  }
  {
    std::cout << "not empty" << std::endl;
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

    std::cout << v << std::endl;
    std::cout << d << std::endl;
    std::cout << arr << std::endl;
    std::cout << lst << std::endl;
    std::cout << flst << std::endl;
    std::cout << m << std::endl;

    std::cout << mm << std::endl;
    std::cout << s << std::endl;
    std::cout << ms << std::endl;
    std::cout << um << std::endl;
    std::cout << umm << std::endl;
    std::cout << us << std::endl;
    std::cout << ums << std::endl;
  }
  std::cout << "test was finished!" << std::endl;
}

}  // namespace my_os
