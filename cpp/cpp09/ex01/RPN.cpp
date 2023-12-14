/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:12 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/12/14 10:01:11 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN& src)
{
    (void)src;
}

RPN::~RPN(void)
{
}

RPN& RPN::operator=(RPN const& rhs)
{
    (void)rhs;
    return *this;
}

token   RPN::operationCheck(char c)
{
    if (c == '+') return plus;
    else if (c == '-') return minus;
    else if (c == '*') return multiple;
    else if (c == '/') return divide;
    else if (std::isdigit(c)) return operand;
    else if (c == ' ') return space;
    else return error;
}

int RPN::stackPop(void)
{
    int top = _stack.top();
    _stack.pop();
    return top;
}

bool RPN::calculate(const std::string &input)
{
    int first, second;

    for (std::size_t i = 0; i < input.length(); i++) 
    {
        token   t = operationCheck(input[i]);
        if (t == plus || t == minus || t == multiple || t == divide) {
            if (_stack.size() < 2) return false;
            second = stackPop();
            first = stackPop();
            
            if (t == plus) _stack.push(first + second);
            else if (t == minus) _stack.push(first - second);
            else if (t == multiple) _stack.push(first * second);
            else if (t == divide) {
                if (second == 0) return false;
                else _stack.push(first / second);
            }

        } else if (t == operand) {
            _stack.push(static_cast<int>(input[i] - '0'));
        } else if (t == space) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void RPN::execute(const std::string &input)
{
    if (!calculate(input)) {
        std::cout << "Error" << std::endl;
    } else {
        std::cout << stackPop() << std::endl;
    }
}