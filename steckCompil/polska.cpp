#include <iostream>
#include "steck.hpp"
#include "steckArray.hpp"

int priority(char cText)
{
    if (cText == '(')
        return 0;
    if (cText == ')')
        return 1;
    if (cText == '+' || cText == '-')
        return 2;
    if (cText == '*' || cText == '/')
        return 3;
    if (cText == '^')
        return 4;
    return -1;
}

void polska(const char* expr, int maxDeep = 30)
{
    Stack<char>* stack = new StackArray<char>(maxDeep);

    //  Operator sign('0');
    char cText = '\0';
    try
    {
        for (int i = 0; ((cText = expr[i]) != '\0'); i++)
        {
            switch (priority(cText))
            {
                case 0: //'('
                    stack->push(cText);
                    break;
                case 1: //')'
                    while (!stack->isEmpty())
                    {
                        char stackHead = stack->pop();
                        if (stackHead == '(')
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
                        char stackHead = stack->pop();
                        if (stackHead != '(')
                        {
                            std::cout << stackHead;
                        }
                        else
                        {
                            stack->push(stackHead);
                            break;
                        }
                    }
                    stack->push(cText);
                    break;
                case 3: //'*', '/'
                    while (!stack->isEmpty())
                    {
                        char stackHead = stack->pop();
                        if (priority(stackHead) >= 3)
                        {
                            std::cout << stackHead;

                        }
                        else
                        {
                            stack->push(stackHead);
                            break;
                        }
                    }
                    stack->push(cText);
                    break;
                case 4: //'^'
                    stack->push(cText);
                    break;
                case -1: //'A...Z'
                    std::cout << cText;
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
