#pragma once
#include <stack>
#include <map>
#include <string>

class Calculator
{
private:
    std::string RPNstring;
    static double getValue(std::map<std::string, double>& var_map, std::string& str);
    static std::string RPN(std::string str);
public:
    Calculator();
    void setExpression(std::string& new_expression);
    double getResult(std::map<std::string, double>& var_map);
};