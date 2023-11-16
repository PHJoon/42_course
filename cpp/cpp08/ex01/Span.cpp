/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:04:01 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/16 13:04:14 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const Span& src)
{
    std::cout << "Span copy constructor called" << std::endl;
}

Span::~Span(void)
{
    std::cout << "Span destructor called" << std::endl;
}

Span& Span::operator=(Span const& rhs)
{
    std::cout << "Span copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
    }
    return *this;
}