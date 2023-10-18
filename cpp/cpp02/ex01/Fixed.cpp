/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:18:52 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/18 16:10:48 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixed_point_num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixed_point_num): _fixed_point_num(fixed_point_num)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fixed_point_num): _fixed_point_num(fixed_point_num)
{
    
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    _fixed_point_num = src.getRawBits();
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_fixed_point_num = rhs.getRawBits();
    }
    return *this;
}

float Fixed::toFloat(void) const 
{
    return _fixed_point_num;
}
int Fixed::toInt(void) const
{
    return _fixed_point_num;
}

int Fixed::getRawBits(void) const {
    return _fixed_point_num;
}

void Fixed::setRawBits(int const raw) {
    _fixed_point_num = raw;
}

std::ostream& operator << (std::ostream &out, const Fixed &fixed)
{
    out << fixed.getRawBits();
    return out;
}