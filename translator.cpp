#include <cmath>
#include <stack>
#include <cctype>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
#include "translator.h"

double Calculator::getValue(std::map<std::string, double>& var_map, std::string& str)
{
    std::stack<double> value_stack;
    std::stringstream str_stream(str);
    while(!str_stream.eof())
    {
        std::string buffer;
        str_stream >> buffer;
        if(buffer.empty())
        {
            break;
        }
        bool digit_flag = true;
        for(auto x : buffer)
        {
            if((x != '.') && ((x < 48) || (x > 57)))
            {
                digit_flag = false;
                break;
            }
        }
        if(digit_flag)
        {
            double value;
            std::stringstream value_stream(buffer);
            value_stream >> value;
            value_stack.push(value);
        }
        else
        {
            if(buffer == "+")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a + b);

            }
            else if(buffer == "-")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a - b);
            }
            else if(buffer == "*")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a * b);
            }
            else if(buffer == "/")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a / b);
            }
            else if(buffer == "^")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(std::pow(a,b));
            }
            else
            {
                value_stack.push(var_map[buffer]);
            }
        }
    }
    return value_stack.top();
}

std::string Calculator::RPN(std::string str)
{
    std::string::size_type ind;
    while ((ind = str.find(' ')) != std::string::npos) // удаление пробелов из входной строки
    {
        str.erase(ind, 1);
    }

    for (int i = 0; i < str.size(); ++i) // учёт отрицательных чисел
    {
        if ((str[i] == '+' || str[i] == '-') && (0 == i || (!isalnum(str[i - 1]) && str[i - 1] != '.' && str[i - 1] != ')')))
        {
            auto it = std::find_if(str.begin() + i + 1, str.end(), [](char const c) {return !isalnum(c);});
            str.insert(it, ')');
            str.insert(i, "(0");
        }
    }

    for(int i = 0; i < str.length(); i++)           // Цикл разделения строки пробелами
    {
        if(!isalnum(str[i]) && ('.' != str[i]) && (' ' != str[i]))
        {
            str.insert(i, " ");
            str.insert(i+2, " ");
            i+= 2;
        }
    }

    std::map<std::string, size_t> map; // карта весов операций
    map.insert({"cot", 4});
    map.insert({"tan", 4});
    map.insert({"cos", 4});
    map.insert({"sin", 4});
    map.insert({"^", 4});
    map.insert({"*", 3});
    map.insert({"/", 3});
    map.insert({"+", 2});
    map.insert({"-", 2});
    map.insert({"(", 1});
    map.insert({")", 1});

    std::stack<std::string> stack;
    std::stringstream str_stream(str);
    std::string result_str;
    while(!str_stream.eof())
    {
        std::string chunk;
        str_stream >> chunk;
        if(map[chunk] != 0)
        {
            result_str += " ";
            if (")" == chunk)
            {
                while (stack.top() != "(")
                {
                    result_str += stack.top();
                    stack.pop();
                    result_str += " ";
                }
                stack.pop();
            }
            else if (stack.empty() || (map[stack.top()] < map[chunk]) || ("(" == chunk))
            {
                stack.push(chunk);
            }
            else
            {
                do
                {
                    result_str += stack.top();
                    result_str += " ";
                    stack.pop();
                } while (!(stack.empty() || (map[stack.top()] < map[chunk])));
                stack.push(chunk);
            }
        }
        else
        {
            result_str += chunk;
        }
    }
    while (!stack.empty())// остаток из стека добавляется в результ. строку
    {
        result_str += ' ';
        result_str += stack.top();
        result_str += ' ';
        stack.pop();
    }
    return result_str;
}

void Calculator::setExpression(std::string& new_expression)
{
    RPNstring = RPN(new_expression);
}

double Calculator::getResult(std::map<std::string, double>& var_map)
{
    if(RPNstring.empty())
    {
        return 0;
    }
    return getValue(var_map, RPNstring);
}

Calculator::Calculator()
{
    RPNstring = "";
}

/*
int main()
{
    Calculator calc;
    std::string expr = "1 + 2 - x";
    calc.setExpression(expr);
    std::map<std::string, double> var_map = {{"x",10}};
    std::cout << calc.getResult(var_map);
}
*/
