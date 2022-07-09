//
// Created by 魏文俊 on 2022/7/2.
//
#include "template_hpp.h"

// https://blog.csdn.net/weixin_40539125/article/details/83375452
// 首先需要知道的是把模版类的定义和实现分开写了，编译将会出错


//template<typename T, typename U>
//void People<T, U>::foo2() {
//  std::cout << "static foo2 of template class invoked." << std::endl;
//}
//
//template<typename T>
//void ClassA<T>::foo() {
//  std::cout << "foo of template classA invoked." << std::endl;
//}

//这里分开实现
template <typename T>
void test_foo(const T& t) {
  std::cout << "test_foo invoked." << std::endl;
}
//这里是 显式模板实例化
//如果没有这个操作，其他cpp文件中无法正常调用test_foo
//换句话说，如果一定要把模板函数的定义和实现分离，那么外部使用的每一种特化，都得在这里声明一遍
template <>
void test_foo<int>(const int& t) {
  std::cout << "test_foo<int> invoked." << std::endl;
}



