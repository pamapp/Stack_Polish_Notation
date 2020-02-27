#pragma once

class Operator
{
private:
    unsigned char sign_;
public:
    Operator(): sign_('\0'){}
    Operator(unsigned char s): sign_(s){}
    ~Operator(){}
    
    char getSign()
    {
        return sign_;
    }
    
    int getPriority()
    {
        if (sign_ == '(')
            return 0;
        else if (sign_ == ')')
            return 1;
        else if (sign_ == '+' || sign_ == '-')
            return 2;
        else if (sign_ == '*' || sign_ == '/')
            return 3;
        else if (sign_ == '^')
            return 4;
        else
            return 5;
    }
  
    bool operator!= (const Operator& sign1)
    {
      if (sign_ == sign1.sign_)
        return false;
      else
        return true;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Operator& sign);
};

std::ostream& operator<<(std::ostream& out, const Operator& sign)
{
  out << sign.sign_;
  return out;
}
