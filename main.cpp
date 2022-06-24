#include <iostream>
#include <fstream>
#include "static/static_main.h"
#include "string_test/string_main.h"

// https://github.com/Light-City/CPlusPlusThings

extern void vtable_main();
void static_main();

struct st {
    int aa;
    ~ st() {
        printf("st de");
    };
};

int main() {
//    vtable_main();
//    static_main();
//    static_foo_in_h();

//    int a = 1;
//    {
//        int a = 2;
//        std::cout << "value in block is " << a <<std::endl;
//        {
//            int a = 3;
//        }
//    }

//    std::cout << "value out block is " << a <<std::endl;

    // int a = 1;
    // {
    //     st _st{};
    // }

    string_main();

    return 0;
}
