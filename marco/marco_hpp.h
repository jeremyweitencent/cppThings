//
// Created by 魏文俊 on 2022/7/2.
// https://disenone.github.io/2021/03/31/cpp-preprocess
//

#ifndef CPPTHINGS_MARCO_MARCO_HPP_H_
#define CPPTHINGS_MARCO_MARCO_HPP_H_

#define ITER(arg0, arg1) ITER(arg1, arg0)
//ITER(3, 4)
#define CONCAT_(arg0, arg1) arg0 ## arg1


void marco_test_main() {
  std::cout << "" << std::endl;
}

#endif //CPPTHINGS_MARCO_MARCO_HPP_H_
