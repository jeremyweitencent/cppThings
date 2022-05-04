#include <iostream>
#include <fstream>

// https://github.com/Light-City/CPlusPlusThings

extern void vtable_main();


int main() {
//    vtable_main();
//    std::cout << "plz input" << std::endl;
//    int a;
//    std::string s;
//    std::cin >> a >> s;
//    std::cout << "a is " << a << " s is: " << s << std::endl;
    std::ifstream is("../text.txt");
//    int v;
//    is >> v;
//    std::cout << "v is " << v << std::endl;
    if (is.is_open()) {
        while (!is.eof()) {
            char str[256];
            std::string str2;
            getline(is, str2);
            std::cout << std::setw(20) << std::left  <<
            std::setfill('*') << std::setfill('0') <<
            str2 << std::endl;
        }
    }

    return 0;
}
