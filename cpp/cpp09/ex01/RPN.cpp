/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:57:12 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/24 16:57:15 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
    std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const RPN& src)
{
    std::cout << "RPN copy constructor called" << std::endl;
}

RPN::~RPN(void)
{
    std::cout << "RPN destructor called" << std::endl;
}

RPN& RPN::operator=(RPN const& rhs)
{
    std::cout << "RPN copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
    }
    return *this;
}