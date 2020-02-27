#include <iostream>
#include <math.h>
#include "steck.hpp"
#include "steckArray.hpp"
#include "operator.hpp"

void polska(const char* expr, int maxDeep = 30)
{
    Stack<Operator>* stack = new StackArray<Operator>(maxDeep);
    
    Operator sign('\0');
    
    try
    {
        for (int i = 0; ((sign = expr[i]) != '\0'); i++)
        { 
            switch (sign.getPriority())
            {
                case 0: //'('
                    stack->push(sign);
                    break;
                case 1: //')'
                    while (!stack->isEmpty())
                    {
                        Operator stackHead = stack->pop();
                        if (stackHead.getSign() == '(')
                        {
                            break;
                        }
                        else
                        {
                            std::cout << stackHead;
                        }
                    }
                    break;
                case 2: //'+', '-'
                    while (!stack->isEmpty())
                    {
                        Operator stackHead = stack->pop();
                        if (stackHead.getSign() != '(')
                        {
                            std::cout << stackHead;
                        }
                        else
                        {
                            stack->push(stackHead);
                            break;
                        }
                    }
                    stack->push(sign);
                    break;
                case 3: //'*', '/'
                    while (!stack->isEmpty())
                    {
                        Operator stackHead = stack->pop();
                        if (stackHead.getPriority() >= 3)
                        {
                            std::cout << stackHead;
                        }
                        else
                        {
                            stack->push(stackHead);
                            break;
                        }
                    }
                    stack->push(sign);
                    break;
                case 4: //'^'
                    stack->push(sign);
                    break;
                case 5: //'0...9'
                    std::cout << sign;
                    break;
            }
        }
        while (!stack->isEmpty())
        {
            cout << stack->pop();
        }
    }
    catch (StackUnderflow)
    {
        std::cout << "Error Under";
    }
    catch (StackOverflow)
    {
        std::cout << "Error Over";
    }
}


void calculate(const char* expr, int maxDeep = 30)
{
    Stack<int>* stack = new StackArray<int>(maxDeep);
    
    Operator sign('\0');
    int oper1;
    int oper2;
    int result;
    
    try
    {
        for (int i = 0; ((sign = expr[i]) != 0); i++)
        {
            switch (sign.getPriority())
            {
                case 2: //'+', '-'
                    oper1 = stack->pop();
                    oper2 = stack->pop();
                    if (sign.getSign() == '+')
                        result = oper2 + oper1;
                    else
                        result = oper2 - oper1;
                    stack->push(result);
                    break;
                case 3: //'*', '/'
                    oper1 = stack->pop();
                    oper2 = stack->pop();
                    if (sign.getSign() == '*')
                        result = oper2 * oper1;
                    else if (oper1 == 0 || oper2 == 0)
                    {
                        std::cout << "Zero Division";
                        break;
                    }
                    else
                        result = oper2 / oper1;
                    stack->push(result);
                    break;
                case 4: //'^'
                    oper1 = stack->pop();
                    oper2 = stack->pop();
                    result = pow(oper2, oper1);
                    stack->push(result);
                    break;
                case 5: //'0...9'
                    char cText = sign.getSign();
                    result = std::atoi(&cText);
                    stack->push(result);
                    break;
            }
        }
        while (!stack->isEmpty())
        {
            cout << stack->pop();
        }
    }
    catch (StackUnderflow)
    {
        std::cout << "Error Under";
    }
    catch (StackOverflow)
    {
        std::cout << "Error Over";
    }
}
