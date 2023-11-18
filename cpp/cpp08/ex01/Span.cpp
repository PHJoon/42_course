/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:11:23 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/18 21:09:13 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _vector(0)
{
}

Span::Span(unsigned int n): _vector(n)
{
}

Span::Span(const Span& src): _vector(src._vector)
{
}

Span::~Span(void)
{
}

Span& Span::operator=(Span const& rhs)
{
    if (this != &rhs)
    {
        this->_vector = rhs._vector;
    }
    return *this;
}

void Span::addNumber(int n)
{
    
        throw FullSpanException();
    _vector.push_back(n);
}

const unsigned int Span::shortestSpan(void) const
{
    unsigned int ret = 0;
    for (std::vector<int>::iterator iter = _vector.begin(); iter != _vector.end(); iter++)
    {
        
    }
    
    
}

const unsigned int Span::longestSpan(void) const
{
    
}

const char *Span::FullSpanException(void) const throw()
{
    return "Span is Full";
}

const char *Span::NoSpanException(void) const throw()
{
    return "There is no Span";
}