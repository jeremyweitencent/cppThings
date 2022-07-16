#include <iostream>

// 位域
struct _PRCODE {
    unsigned int code1: 2;
    unsigned int code2: 2;
    unsigned int code3: 8;
};

typedef struct {
    unsigned int int1;
    unsigned int int2;
    unsigned int int3;
} normal;

typedef struct {

    public:
    
    void foo() {
        std::cout << "foo in empty invoked" << std::endl;
        foo2();
    }

    private:
    void foo2() {
        std::cout << "foo in empty invoked" << std::endl;
    }

} empty;


union test_union {
    int var1;
    void foo() {
        std::cout << "foo in union invoked" << std::endl;
    }
        void foo2() {
        std::cout << "foo in union invoked" << std::endl;
    }
        void foo3() {
        std::cout << "foo in union invoked" << std::endl;
    }
        void foo4() {
        std::cout << "foo in union invoked" << std::endl;
    }
        void foo5() {
        std::cout << "foo in union invoked" << std::endl;
    }
        void foo6() {
        std::cout << "foo in union invoked" << std::endl;
    }
};

void bits_test_main() {
    struct _PRCODE prcode{1,3,20};
    std::cout << sizeof(prcode) << std::endl;
    empty e;
    e.foo();
    std::cout << sizeof(e) << std::endl;
    normal n;
    std::cout << sizeof(n) << std::endl;
    test_union u;
    std::cout << sizeof(u) << std::endl;
    u.foo();
}