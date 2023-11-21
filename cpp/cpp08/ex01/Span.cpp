/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:11:23 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/21 11:08:33 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _vector(0), _vSize(0), _idx(0)
{
}

Span::Span(unsigned int n): _vector(n), _vSize(n), _idx(0)
{
}

Span::Span(const Span& src): _vector(src._vector), _vSize(src._vSize), _idx(src._idx)
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
        this->_vSize = rhs._vSize;
        this->_idx = rhs._idx;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (_idx == _vSize) {
        throw FullSpanException();
    }
    
    _vector[_idx] = n;
    _idx += 1;
}

unsigned int Span::shortestSpan(void) const
{
    if (_idx < 2) throw NoSpanException();
    
    std::vector<int> temp(_idx);
    std::copy(_vector.begin(), _vector.begin() + _idx, temp.begin());
    std::sort(temp.begin(), temp.end());

    unsigned int ret = std::numeric_limits<unsigned int>::max();
    for (std::vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
    {
        if (iter + 1 != temp.end())
        {
            unsigned int retTemp = static_cast<unsigned int>(*(iter + 1) - *iter);
            ret = std::min(ret, retTemp);
        }
    }
    return ret;
}

unsigned int Span::longestSpan(void) const
{
    if (_idx < 2) throw NoSpanException();
    
    int min = *std::min_element(_vector.begin(), _vector.begin() + _idx);
    int max = *std::max_element(_vector.begin(), _vector.begin() + _idx);
    return max - min;
}

std::vector<int>::iterator Span::getBegin(void)
{
    return _vector.begin();
}

std::vector<int>::iterator Span::getEnd(void)
{
    return _vector.end();
}

void Span::fillSpan(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    if (_idx == _vSize) {
        throw FullSpanException();
    } else if (_idx != 0) {
        throw NotEmptyException();
    }
    srand(time(NULL));
    for (std::vector<int>::iterator iter = first; iter != last; iter++)
    {
        *iter = rand();
    }
    _idx = std::distance(first, last);
}

const char *Span::FullSpanException::what(void) const throw()
{
    return "Span Is full";
}

const char *Span::NoSpanException::what(void) const throw()
{
    return "No Span Is Found";
}

const char *Span::NotEmptyException::what(void) const throw()
{
    return "Span Is Not Empty";
}

void Span::printAll(void) const
{
    for (unsigned int i = 0; i < _idx; i++)
    {
        std::cout << i << "  :  " << _vector[i] << std::endl;
    }
}
