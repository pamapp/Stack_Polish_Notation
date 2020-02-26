#include <iostream>
#include "operator.hpp"

int priority(char cText);
void polska(const char* expr, int maxDeep = 30);
void calculate(const char* expr, int maxDeep = 30);
int main()
{
    Operator op('(');
    std::cout << op.getPriority();
//    std::cout << "=========================================" << std::endl;
//    std::cout << "Polska Tests:" << std::endl;
//    const char* test01 = "(1*3)+5";
//    const char* test02 = "((4*(6-3))+((8-6)/2))";
//    const char* test03 = "(1+2)*(3+2)/4";
//    const char* test04 = "(1*2)^4";
//    const char* test05 = "(1-2)-(3-2)-4";
//    const char* test06 = "(4*(6-3))^(8-6-2)";
//    const char* test07 = "(A+B)*(C+D)";
//
//    polska(test01);
//    std::cout << std::endl;
//    polska(test02);
//    std::cout << std::endl;
//    polska(test03);
//    std::cout << std::endl;
//    polska(test04);
//    std::cout << std::endl;
//    polska(test05);
//    std::cout << std::endl;
//    polska(test06);
//    std::cout << std::endl;
//    polska(test07);
//    std::cout << std::endl;
//
//    std::cout << "=========================================" << std::endl;
//    std::cout << "Calculate Tests:" << std::endl;
//    const char* test1 = "13*5+";
//    const char* test2 = "463-*86-2/+";
//    const char* test3 = "12+32+*4/";
//    const char* test4 = "12*4^";
//    const char* test5 = "12-32--4-";
//    const char* test6 = "463-*86-2-^";
//
//    calculate(test1);
//    std::cout << std::endl;
//    calculate(test2);
//    std::cout << std::endl;
//    calculate(test3);
//    std::cout << std::endl;
//    calculate(test4);
//    std::cout << std::endl;
//    calculate(test5);
//    std::cout << std::endl;
//    calculate(test6);
//    std::cout << std::endl;
//
  return 0;
}
