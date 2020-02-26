#pragma once

class Operator
{
private:
    const char sign_;
    int priority_;
public:
    Operator(const char s): sign_(s){}
    ~Operator(){}
    int getPriority()
    {
        if (sign_ == '(')
            return this->priority_ = 0;
        else if (sign_ == ')')
            return this->priority_ = 1;
        else if (sign_ == '+' || sign_ == '-')
            return this->priority_ = 2;
        else if (sign_ == '*' || sign_ == '/')
            return this->priority_ = 3;
        else if (sign_ == '^')
            return this->priority_ = 4;
        else
            return this->priority_ = -1;
    }

};
