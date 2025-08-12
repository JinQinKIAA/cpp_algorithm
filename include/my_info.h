#pragma once

#include <cxxabi.h>

#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>

namespace my_info {

template <typename T>
std::string GetTypeName(const T& t) {
  auto type = abi::__cxa_demangle(typeid(t).name(), nullptr, nullptr, nullptr);
  return type;
}

template <typename T>
std::string GetAddress(const T& t) {
  auto address = (unsigned long)&t;
  std::ostringstream os;
  os << "[ " << address << " ]";
  return os.str();
}

template <typename T>
void info(const T& t,
          typename std::enable_if<std::is_pointer<T>::value>::type* = 0) {
  // auto address = GetAddress(t);
  auto type = GetTypeName(t);
  // std::cout << "内置指针" << std::endl;
  auto value_address = GetAddress(*t);
  auto value_type = GetTypeName(*t);
  std::cout << "[built-in]➤\t" << value_type << value_address << '\n';
}

template <typename T>
void info(const T& t,
          typename std::enable_if<!std::is_pointer<T>::value>::type* = 0) {
  auto address = GetAddress(t);
  auto type = GetTypeName(t);
  // std::cout << "不是指针" << std::endl;
  std::cout << type << address << '\n';
}

template <typename T>
void info(std::shared_ptr<T>& t) {
  // std::cout << "shared_ptr" << std::endl;
  // auto address = GetAddress(t);
  // auto type = GetTypeName(t);
  auto value_address = GetAddress(*t);
  auto value_type = GetTypeName(*t);
  auto use_count = t.use_count();
  std::cout << "[ shared ]➤ \t" << value_type << value_address
            << "\tuse_count[ " << use_count << " ]\n";
}

//必须用引用 因为unique_ptr禁止拷贝赋值
template <typename T>
void info(std::unique_ptr<T>& t) {
  // std::cout << "unique_ptr" << std::endl;
  // auto address = GetAddress(t);
  // auto type = GetTypeName(t);
  auto value_address = GetAddress(*t);
  auto value_type = GetTypeName(*t);
  std::cout << "[ unique ]➤ \t" << value_type << value_address << '\n';
}

template <typename T>
void info(std::weak_ptr<T>& t) {
  // std::cout << "weak_ptr" << std::endl;
  if (std::shared_ptr<T> np = t.lock()) {
    // auto address = GetAddress(t);
    // auto type = GetTypeName(t);
    auto value_address = GetAddress(*np);
    auto value_type = GetTypeName(*np);
    auto use_count = t.use_count();
    std::cout << "[  weak  ]➤ \t" << value_type << value_address
              << "\tuse_count[ " << use_count << " ]\n";
  } else {
    std::cout << "weak_ptr 对象不存在" << std::endl;
  }
}

struct Cat {
  std::string name;
  int age = 0;
};

inline void test() {
  int a = 0;
  int* pa = &a;
  auto sp = std::make_shared<int>(0);
  std::unique_ptr<int> up(new int(0));
  std::weak_ptr<int> wp(sp);
  int* pn = nullptr;
  info(a);
  info(pa);
  info(sp);
  info(up);
  info(wp);
  info(pn);

  Cat c;
  Cat* pc = &c;
  info(c);
  info(pc);
}
}  // namespace my_info
