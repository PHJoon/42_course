/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:10 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/03 16:15:24 by hyungjpa         ###   ########.fr       */
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



void    ScalarConverter::setValue(const char *str)
{
    char *endptr = NULL;
    _input = str;
    if (str == "nan" || str == "nanf" || str == "inf" || str == "inff" || str == "-inf" || str == "-inff") {
        _nFlag = true;
    } else {
        _inputD = strtod()
    }
}


void    ScalarConverter::convert(const char *str)
{
    double input = std::stod(str);
    std::cout << std::fixed;


    
    std::cout << "char: " << std::endl;
    std::cout << "int: " <<  std::endl;
    std::cout << "float: " << std::endl;
    std::cout << "double: " <<  std::endl;
}