/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:18:52 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/21 16:33:59 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixed_point_num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixed_point_num): _fixed_point_num(fixed_point_num << _fractional_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fixed_point_num): _fixed_point_num(static_cast<int>(roundf(fixed_point_num * (1 << _fractional_bits))))
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
    return static_cast<float>(_fixed_point_num) / (1 << _fractional_bits);
}
int Fixed::toInt(void) const
{
    return _fixed_point_num >> _fractional_bits;
}

int Fixed::getRawBits(void) const {
    return _fixed_point_num;
}

void Fixed::setRawBits(int const raw) {
    _fixed_point_num = raw;
}

std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}