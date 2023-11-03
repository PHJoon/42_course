/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:10 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/03 17:04:45 by hyungjpa         ###   ########.fr       */
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



void    ScalarConverter::setValue(const std::string input)
{
    char *endptr = NULL;
    _input = input;
    if (input == "nan" || input == "nanf" || input == "inf" || input == "inff" || input == "-inf" || input == "-inff") {
        _nFlag = true;
    } else {
        _inputD = strtod(input.c_str(), &endptr);
        if (*endptr && std::strcmp(endptr, "f")) {
            // 에러
        }
        _pFlag = true;
        _c = static_cast<char>(_inputD);
        _i = static_cast<int>(_inputD);
        _f = static_cast<float>(_inputD);
        _d = static_cast<double>(_inputD);
    }
}


void    ScalarConverter::convert(const std::string input)
{
    std::cout << std::fixed;
    setValue(input);

    
    std::cout << "char: " << _c << std::endl;
    std::cout << "int: " <<  _i << std::endl;
    std::cout << "float: " << _f << std::endl;
    std::cout << "double: " << _d << std::endl;
}