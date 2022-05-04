//
// Created by 魏文俊 on 2022/5/2.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef void (*Fun) ();

class Base {
public:
    Base() = default;
    virtual void fun1() {
        cout << "Base::fun1()" << endl;
    }
    virtual void fun2() {
        cout << "Base::fun2()" << endl;
    }
    virtual void fun3() {}
    ~Base() = default;
};

class Derived : public Base {
public:
    Derived() = default;;
    void fun1() override {
        cout << "Derived::fun1()" << endl;
    }
    void fun2() override {
        cout << "DerivedClass::fun2()" << endl;
    }
    ~Derived() = default;;
};

Fun getAddr(void *obj, unsigned int offset) {
    cout<<"======================="<<endl;
    void *vptr_addr = reinterpret_cast<void *>(*(unsigned long *)obj);
    printf("vptr_addr:%p\n", vptr_addr);
    void *func_addr = reinterpret_cast<void *>(*((unsigned long *)vptr_addr + offset));
    printf("func_addr:%p\n", func_addr);
    return (Fun) func_addr;
}

void vtable_main() {
    Base ptr;
    Derived d;
    Base *pt = new Derived();
    Base &pp = ptr;
    Base &p = d;
    cout<<"基类对象直接调用"<<endl;
    ptr.fun1();
    cout<<"基类引用调用基类实例"<<endl;
    pp.fun1();
    cout<<"基类指针指向基类实例并调用虚函数"<<endl;
    pt->fun1();
    cout<<"基类引用指向基类实例并调用虚函数"<<endl;
    p.fun1();

    Fun f1 = getAddr(pt, 0);
    (*f1)();
    Fun f2 = getAddr(pt ,1);
    (*f2)();

    delete pt;
}