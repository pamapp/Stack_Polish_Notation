#include <iostream>
#include "steck.hpp"
#include "steckArray.hpp"

#include <math.h>

int priority(char cText);
void calculate(const char* expr, int maxDeep = 30)
{
    Stack<int>* stack = new StackArray<int>(maxDeep);

    //  Operator sign('0');
    char cText = '\0';
    int oper1;
    int oper2;
    int result;

    for (int i = 0; ((cText = expr[i]) != 0); i++)
    {
        switch (priority(cText))
        {
            case 2:
                oper1 = stack->pop();
                oper2 = stack->pop();
                if (cText == '+')
                    result = oper2 + oper1;
                else
                    result = oper2 - oper1;
                stack->push(result);
                break;
            case 3:
                oper1 = stack->pop();
                oper2 = stack->pop();
                if (cText == '*')
                    result = oper2 * oper1;
                else
                    result = oper2 / oper1;
                stack->push(result);
                break;
            case 4:
                oper1 = stack->pop();
                oper2 = stack->pop();
                result = pow(oper2, oper1);
                stack->push(result);
                break;
            case -1:
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
