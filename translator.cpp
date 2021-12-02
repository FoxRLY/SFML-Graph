#include <cmath>
#include <stack>
#include <cctype>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
#include <iostream>
#include "translator.h"

/*
void stackPrint(std::stack<double>& stack)
{
    std::stack<double> buffer;
    std::cout << "Stack: ========================\n";
    while(!stack.empty())
    {
        std::cout << stack.top() << std::endl;
        buffer.push(stack.top());
        stack.pop();
    }
    std::cout << "===============================\n";
    while(!buffer.empty())
    {
        stack.push(buffer.top());
        buffer.pop();
    }
}
*/

double Calculator::getValue(std::map<std::string, double>& var_map, std::string& str)
{
    std::stack<double> value_stack;

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
    std::stringstream test_stream(str);
    std::cout << "String: ";
    while(!test_stream.eof())
    {
        std::string buffer;
        test_stream >> buffer;
        std::cout << buffer << " ";
    }
    std::cout << std::endl;
    std::stringstream str_stream(str);
    while(!str_stream.eof())
    {
        std::string buffer;
        str_stream >> buffer;
        if(buffer == "")
        {
            break;
        }
        bool digit_flag = true;
        if(map[buffer] != 0)
        {
            digit_flag = false;
        }
        if(digit_flag)
        {
            if(var_map.find(buffer) != var_map.end())
            {
                value_stack.push(var_map[buffer]);
                //std::cout << "Variable Pushed " << var_map[buffer] << std::endl;
            }
            else
            {
                double value;
                std::stringstream value_stream(buffer);
                value_stream >> value;
                value_stack.push(value);
                //std::cout << "Digit Pushed " << value << std::endl;
            }
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
                /*
                std::cout << a << " + " << b << " = " << a+b << std::endl;
                std::cout << "Popped " << b << std::endl;
                std::cout << "Popped " << a << std::endl;
                std::cout << "Pushed " << a + b << std::endl;
                */
            }
            else if(buffer == "-")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a - b);
                /*
                std::cout << a << " - " << b << " = " << a-b << std::endl;
                std::cout << "Popped " << b << std::endl;
                std::cout << "Popped " << a << std::endl;
                std::cout << "Pushed " << a - b << std::endl;
                */
            }
            else if(buffer == "*")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a * b);
                /*
                std::cout << a << " * " << b << " = " << a*b << std::endl;
                std::cout << "Popped " << b << std::endl;
                std::cout << "Popped " << a << std::endl;
                std::cout << "Pushed " << a * b << std::endl;
                */
            }
            else if(buffer == "/")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(a / b);
                /*
                std::cout << a << " / " << b << " = " << a/b << std::endl;
                std::cout << "Popped " << b << std::endl;
                std::cout << "Popped " << a << std::endl;
                std::cout << "Pushed " << a / b << std::endl;
                */
            }
            else if(buffer == "^")
            {
                double b = value_stack.top();
                value_stack.pop();
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(std::pow(a,b));
                /*
                std::cout << a << " ^ " << b << " = " << std::pow(a,b) << std::endl;
                std::cout << "Popped " << b << std::endl;
                std::cout << "Popped " << a << std::endl;
                std::cout << "Pushed " << std::pow(a,b) << std::endl;
                */
            }
            else if(buffer == "sin")
            {
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(sin(a));
                /*
                std::cout << "sin( " << a << " ) = " << sin(a) << std::endl;
                std::cout << "Popped " << a << std::endl;
                std::cout << "Pushed " << sin(a) << std::endl;
                */
            }
            else if(buffer == "cos")
            {
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(cos(a));
                /*
                std::cout << "cos( " << a << " ) = " << cos(a) << std::endl;
                std::cout << "Popped " << a << std::endl;
                std::cout << "Pushed " << cos(a) << std::endl;
                */
            }
            else if(buffer == "tan")
            {
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(tan(a));
                /*
                std::cout << "tan( " << a << " ) = " << tan(a) << std::endl;
                std::cout << "Popped " << a << std::endl;
                std::cout << "Pushed " << tan(a) << std::endl;
                */
            }
            else if(buffer == "cot")
            {
                double a = value_stack.top();
                value_stack.pop();
                value_stack.push(1.0/tan(a));
                /*
                std::cout << "cot( " << a << " ) = " << 1.0/tan(a) << std::endl;
                std::cout << "Popped " << a << std::endl;
                std::cout << "Pushed " << 1.0/tan(a) << std::endl;
                */
            }
        }
        //stackPrint(value_stack);
    }
    return value_stack.top();
}

std::string Calculator::RPN(std::string str)
{
    for(int i = 0; i < str.length(); i++)           // Цикл разделения строки пробелами
    {
        std::cout << str[i] << std::endl;
        if(!isalnum(str[i]) && ('.' != str[i]) && (' ' != str[i]))
        {
            str.insert(i, " ");
            str.insert(i+2, " ");
            i += 1;
        }
    }
    
    std::cout << str << std::endl;

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

/*
std::string Calculator::RPN(std::string str)
{
    std::string srpn;


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

    std::map<char, size_t> map; // карта весов символов
    map.insert({'^', 4});
    map.insert({'*', 3});
    map.insert({'/', 3});
    map.insert({'+', 2});
    map.insert({'-', 2});
    map.insert({'(', 1});
    std::stack<char> stack;
    for (auto c : str) // формировка результирующей строки в ОПЗ
    {
        if (!isalnum(c) && ('.' != c))  // если символ не буквенно-циферный и не точка
        {
            srpn += ' ';
            if (')' == c)
            {
                while (stack.top() != '(')
                {
                    srpn += stack.top();
                    stack.pop();
                    srpn += ' ';
                }
                stack.pop();
            }
            else if (stack.empty() || (map[stack.top()] < map[c]) || ('(' == c))
            {
                stack.push(c);
            }
            else
            {
                do
                {
                    srpn += stack.top();
                    srpn += ' ';
                    stack.pop();
                } while (!(stack.empty() || (map[stack.top()] < map[c])));
                stack.push(c);
            }
        }
        else
        {
            srpn += c;
        }
    }
    while (!stack.empty())// остаток из стека добавляется в результ. строку
    {
        srpn += ' ';
        srpn += stack.top();
        srpn += ' ';
        stack.pop();
    }

    return srpn;
}
*/

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
    std::cout << RPNstring << std::endl;
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
    std::string expr;
    std::getline(std::cin, expr);
    calc.setExpression(expr);
    std::map<std::string, double> var_map = {{"pi",3.14}};
    std::cout << calc.getResult(var_map);
}
*/