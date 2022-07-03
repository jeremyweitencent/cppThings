//
// Created by 魏文俊 on 2022/7/2.
// https://disenone.github.io/2021/03/31/cpp-preprocess
// https://juejin.cn/post/6884575803523203080
// https://zhuanlan.zhihu.com/p/26978356
// https://zhuanlan.zhihu.com/p/27019165
// https://zhuanlan.zhihu.com/p/27024686
//

#ifndef CPPTHINGS_MARCO_MARCO_HPP_H_
#define CPPTHINGS_MARCO_MARCO_HPP_H_

#define ITER(arg0, arg1) ITER(arg1, arg0)
//ITER(3, 4)
#define CONCAT(arg0, arg1) arg0 ## arg1
//CONCAT(Hello, CONCAT(World, !))
//CONCAT(CONCAT(he, ll) o, world!)

#define ADD_COMMA(a0, a1) a0, a1
//ADD_COMMA(,b)
//ADD_COMMA(ADD_COMMA(1,2), ADD_COMMA(5,5))

#define STRINGIZE(a0) # a0
//#define STRINGIZE_IMPL(a0) # a0
//#define STRINGIZE(a0) STRINGIZE_IMPL(a0)
//STRINGIZE_IMPL(ADD_COMMA(1, 2))
//STRINGIZE(waht)
//CONCAT(STRING, IZE(Hello))

#define PP_LPAREN() (
#define PP_RPAREN() )
#define PP_COMMA() ,
#define PP_EMPTY()
#define PP_HASHHASH # ## #      // 表示 ## 字符串，但只是作为字符串，不会当作 ## 操作符来处理

#define PP_IDENTITY(arg0) arg0
#define PP_CONCAT(arg0, arg1) PP_CONCAT_IMPL(arg0, arg1)
#define PP_CONCAT_IMPL(arg0, arg1) arg0 ## arg1
//延迟拼接
//PP_CONCAT(PP_IDENTITY(1), PP_IDENTITY(2))

//logic
#define PP_BOOL(a0) PP_CONCAT(PP_BOOL_, a0)
#define PP_BOOL_0 0
#define PP_BOOL_1 1

#define PP_NOT(a0) PP_CONCAT(PP_NOT_, PP_BOOL(a0))
#define PP_NOT_0 1
#define PP_NOT_1 0

#define PP_AND(arg0, arg1) PP_CONCAT(PP_AND_, PP_CONCAT(PP_BOOL(arg0), PP_BOOL(arg1)))
#define PP_AND_00 0
#define PP_AND_01 0
#define PP_AND_10 0
#define PP_AND_11 1

#define PP_OR(arg0, arg1) PP_CONCAT(PP_OR_, PP_CONCAT(PP_BOOL(arg0), PP_BOOL(arg1)))
#define PP_OR_00 0
#define PP_OR_01 1
#define PP_OR_10 1
#define PP_OR_11 1

void marco_test_main() {
//  std::cout << STRINGIZE(split) << std::endl;
}

#endif //CPPTHINGS_MARCO_MARCO_HPP_H_
