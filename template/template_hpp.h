//
// Created by 魏文俊 on 2022/7/2.
// https://sg-first.gitbooks.io/cpp-template-tutorial/content/TMP_ji_chu_md.html
//

#ifndef CPPTHINGS_TEMPLATE_TEMPLATE_HPP_H_
#define CPPTHINGS_TEMPLATE_TEMPLATE_HPP_H_

#include <iostream>
#include <list>

// 模板限定-只有当std::enable_if<?>中的表达式为true是，才有type字段，否则编译出错
//template<typename T, typename = typename std::enable_if<std::is_pod<T>::value>::type>
template<typename T>
struct People {
//  static_assert(std::is_pod<T>::value == true, "err");
  friend T;
  T t;
  inline void print() {
    std::cout << t << std::endl;
  }
  template<typename U, typename = typename std::enable_if<std::is_pod<U>::value>::type>
  inline void foo() {std::cout << "foo invoked." << std::endl;};
  inline void foo2();
};

template<typename T>
inline void People<T>::foo2() {
  std::cout << "static foo2 of template class invoked." << std::endl;
}


template <typename T>
struct ClassA {
  T member;
//  static void foo() {
//    std::cout << "static foo of template classA invoked." << std::endl;
//  }
  static void foo();
};

template <typename T>
void ClassA<T>::foo() {
  std::cout << "static foo of template classA invoked." << std::endl;
}

template <typename T> class A {};

template <typename T> T foo(A<T> v);

static float data[1024] = {};
template <typename T>
T GetValue(int i) {
  return static_cast<T>(data[i]);
}

//这里的顺序，影响着调用方是是否可以只指定D(my_cast<D>(param))来调用
//编译器的自动推导是有顺序的，需要先写需要人工指定的模板参数，期望编译器由实参推导的要放在后面
//编译器没法根据返回值推断类型，因为函数调用的时候，返回值被谁接收是不一定的
template <typename D, typename S>
D my_cast(S s) {
  return (D)s;
}


template <typename T, int size>
struct Array {
    T data[size];
  };

//开始类型体操
template <int i>
struct AA {
  void foo(int) {}
};
template <uint8_t a, typename b, void *c>
class BB{};
template <bool, void (*a)()>
class CC{};
template <void (AA<3>::*a)(int)>
class DD{}; //DD(&AA<3>::foo) d;

//error, must be int
//template <float f> struct EE {};

template <typename T> struct X {};
template <typename T>
struct Y {
  typedef X<T> ReboundType;                        // 类型定义1
  typedef typename X<T>::MemberType MemberType;    // 类型定义2
//  typedef UnknownType MemberType3;                // 类型定义3
};

template <typename T>
void foo_test(const T& t) {
  std::cout<<t<<std::endl;
}

//template <typename T>
//void SFINAE_TEST(const T& t, typename std::enable_if<std::is_pod<T>::value>::type* = nullptr) {
////  static_assert(std::is_pod<T>::value);
//  std::cout << "SFINAE_TEST pod version invoked." << std::endl;
//}

//函数模板特化，一定要搞成内联，或者static，否则被其他模块引用，会造成符号重复
template <typename T>
static inline void SFINAE_TEST(const T& t) {
  std::cout << "SFINAE_TEST normal version invoked." << std::endl;
}
template <>
static inline void SFINAE_TEST<int>(const int& t) {
  std::cout << "SFINAE_TEST int version invoked." << std::endl;
}

template <typename T, typename index>
auto authAndAcess(T &t, index i) -> decltype(t[i]) {
  return t[i];
}

// 结合 decltype 可以让IDE显示类型的名称
// TestType<decltype<whatever_xxx>> type_xxx;
template <typename T>
struct TestType;

template <typename T>
void test_foo(const T& t);

//使用using 语句，可以直接做模板类型做重命名，但是typedef不行
template <typename T>
using MyAllocType = std::list<T>;
MyAllocType<int> typeList;

//todo CRTP 实现

#endif //CPPTHINGS_TEMPLATE_TEMPLATE_HPP_H_
