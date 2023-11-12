/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:10 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/12 18:08:24 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0.0f;
double ScalarConverter::_double = 0.0;

bool ScalarConverter::_displayableFlag = true;
bool ScalarConverter::_cImpossibleFlag = false;
bool ScalarConverter::_iImpossibleFlag = false;
bool ScalarConverter::_fImpossibleFlag = false;
bool ScalarConverter::_infFlag = false;

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
    (void)src;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs)
{
    (void)rhs;
    return *this;
}

// pseudo_literals
bool    ScalarConverter::checkPseudoLiterals(double n)
{
    if (isnan(n) || isinf(n)) 
    {
        if (isinf(n)) {
            _infFlag = true;
        }
        return true;
    }
    return false;
}

void ScalarConverter::convertChar(double n)
{
    if (checkPseudoLiterals(n)) {
        _cImpossibleFlag = true;
    } else {
        int num = static_cast<int>(n);
        if ((num >= 0 && num < 32) || num == 127) {
            _displayableFlag = false;
        } else if (num >= 32 && num < 127) {
            _char = static_cast<char>(n);       
        } else {
            _cImpossibleFlag = true;
        }   
    }
}

void ScalarConverter::convertInt(double n)
{
    if (checkPseudoLiterals(n)) {
        _iImpossibleFlag = true;
    } else {
        if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max()) {
            _iImpossibleFlag = true;
        } else {
            _int = static_cast<int>(n);
        }
    }
}

void ScalarConverter::convertFloat(double n)
{
    if (checkPseudoLiterals(n)) {
        _float = static_cast<float>(n);
    } else {
        if (n < -std::numeric_limits<float>::max() || n > std::numeric_limits<float>::max()) {
            _fImpossibleFlag = true;
        } else {
            _float = static_cast<float>(n);
        }
    }
}

void ScalarConverter::convertDouble(double n)
{
    _double = n;
}

void ScalarConverter::printAll(void)
{
    if (_cImpossibleFlag) {
        std::cout << "char: impossible" << std::endl; 
    } else {
        if (!_displayableFlag) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << _char << "'" << std::endl;
        }
    }

    if (_iImpossibleFlag) {
        std::cout << "int: impossible" << std::endl; 
    } else {
        std::cout << "int: " << _int << std::endl;
    }

    if (_fImpossibleFlag) {
        std::cout << "float: impossible" << std::endl;
    } else {
        if (_infFlag) {
            std::cout << std::showpos << "float: " << _float << "f" << std::endl;
        } else {
            std::cout << std::fixed << "float: " << std::setprecision(1) << _float << "f" << std::endl;
        }
    }

    if (_infFlag) {
        std::cout << std::showpos << "double: " << _double << std::endl;
    } else {
        std::cout << std::fixed << "double: " << std::setprecision(1) << _double << std::endl;
    }
}


void ScalarConverter::convert(const std::string &input)
{
    char *end = NULL;
    double  temp = std::strtod(input.c_str(), &end);
    
    if (input.length() == 1 && *end) {
        temp = static_cast<double>(input[0]);
    } else {
        if (temp == 0.0 && input[0] != '+' && input[0] != '-' && !isdigit(input[0])) {
            std::cerr << "invalid argument!" << std::endl;
            return ;
        } else if (*end && std::strcmp(end, "f")) {
            std::cerr << "invalid argument!" << std::endl;
            return ;
        }
    }

    convertChar(temp);
    convertInt(temp);
    convertFloat(temp);
    convertDouble(temp);

    printAll();
}