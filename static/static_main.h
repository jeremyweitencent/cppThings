//
// Created by bytedance on 2022/5/10.
//

#ifndef CPPTHINGS_STATIC_MAIN_H
#define CPPTHINGS_STATIC_MAIN_H

#include <iostream>

static inline void static_foo_in_h() {
  std::cout << "static_foo_in_h address: " << reinterpret_cast<void *>(static_foo_in_h) << std::endl;
  std::cout << "static_foo_in_h address by force: " << (void *) static_foo_in_h << std::endl;
}

#endif //CPPTHINGS_STATIC_MAIN_H
