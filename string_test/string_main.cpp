#include "string_main.h"
#include <iostream>

using namespace std;

void string_main() {
    cout<<"string_main invoked."<<endl;
    wstring s = L"宽字符测试";
    cout << s.at(1) << endl;
}