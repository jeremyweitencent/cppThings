#include <iostream>
#include <fstream>
#include <vector>
#include "static/static_main.h"
#include "string_test/string_main.h"
#include "template/template_hpp.h"
#include "desgin_patterns/creates/singleton.h"
#include "marco/marco_hpp.h"

// https://github.com/Light-City/CPlusPlusThings

extern void vtable_main();
void static_main();

struct st {
  int aa;
  ~ st() {
    printf("st de");
  };
};

class noncopyable {
 protected:
  noncopyable() = default;
  ~noncopyable() = default;
 private:
  noncopyable(const noncopyable &);
  const noncopyable &operator=(const noncopyable &);
};

class Test : noncopyable {
 public:
  Test() = default;
  ~Test() = default;
//  Test(const Test&) = delete;
//  const Test& operator=(const Test&) = delete;
};

struct TestS : noncopyable {
  TestS() = default;
  ~TestS() = default;
};

struct Node {
  int value;
  Node *next;
  std::vector<int> vector;

  friend std::ostream & operator<<(std::ostream &out, Node &node) {
    out << "value:" << node.value << " next:" << node.next;
    return out;
  }

//  std::ostream & operator<<(std::ostream &out) const {
//    out << "value:" << this->value << " next:" << this->next;
//  }

};


int main() {

  marco_test_main();

  SFINAE_TEST(1);
  SFINAE_TEST(People<Node>());

//  float a = GetValue<float>(0);

//  Array<int ,16> arr{};

//  People<int> people;
//  People<Node> people_f;
//  people_f.foo<int>();
//  people.foo<Node>();
//  people_f.print();
//  std::cout << std::is_pod<Node>::value << std::endl;
//  people.foo2();
//  ClassA<int>::foo();
//  foo_test(1);
//
//  A<int> v;
//  foo(v);

//  Test t;
//  Test t2;
//  TestS t3;
////  TestS t4(t3);
////  t2 = t;
//
//  Node node;
//  std::cout << sizeof(((Node *)nullptr)->value) << std::endl;
//
//  string_main();

  return 0;
}
