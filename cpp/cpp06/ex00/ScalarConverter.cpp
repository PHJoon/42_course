/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:10 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/02 17:54:55 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    // std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
    // std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void)src;
}

ScalarConverter::~ScalarConverter(void)
{
    // std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs)
{
    // std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        (void)rhs;
    }
    return *this;
}

char    ScalarConverter::toChar(const double input)
{
    return static_cast<char>(input);

}

int     ScalarConverter::toInt(const double input)
{
    return static_cast<int>(input);
}

float   ScalarConverter::toFloat(const double input)
{
    return static_cast<float>(input);
}

double  ScalarConverter::toDouble(const double input)
{
    return static_cast<double>(input);
}

void    ScalarConverter::convert(const std::string &str)
{
    double input = std::stod(str);
    std::cout << std::fixed;
    std::cout << input << " " << str << std::endl;
    std::cout << "char: " << toChar(input) << std::endl;
    std::cout << "int: " << toInt(input) << std::endl;
    std::cout << "float: " << toFloat(input) << std::endl;
    std::cout << "double: " << toDouble(input) << std::endl;
}