/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:18:52 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/21 15:53:44 by hyungjpa         ###   ########.fr       */
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

Fixed::Fixed(const Fixed& src): _fixed_point_num(src._fixed_point_num)
{
    std::cout << "Copy constructor called" << std::endl;
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

bool Fixed::operator>(Fixed const& rhs) const
{
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const& rhs) const
{
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const& rhs) const
{
    return this->getRawBits() >= rhs.getRawBits();    
}

bool Fixed::operator<=(Fixed const& rhs) const
{
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const& rhs) const
{
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const& rhs) const
{
    return this->getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const& rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const& rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const& rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const& rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++()
{
    ++_fixed_point_num;
    return *this;    
}

Fixed& Fixed::operator--()
{
    --_fixed_point_num;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed   temp(this->toFloat());
    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed   temp(this->toFloat());
    --(*this);
    return temp;
}

Fixed&   Fixed::min(Fixed& lhs, Fixed& rhs)
{
    if (lhs.toFloat() > rhs.toFloat()) {
        return rhs;
    } else {
        return lhs;
    }
}

Fixed&   Fixed::max(Fixed& lhs, Fixed& rhs)
{
    if (lhs.toFloat() < rhs.toFloat()) {
        return rhs;
    } else {
        return lhs;
    }
}

Fixed const&   Fixed::min(Fixed const& lhs, Fixed const& rhs)
{
    if (lhs.toFloat() > rhs.toFloat()) {
        return rhs;
    } else {
        return lhs;
    }
}

Fixed const&   Fixed::max(Fixed const& lhs, Fixed const& rhs)
{
    if (lhs.toFloat() < rhs.toFloat()) {
        return rhs;
    } else {
        return lhs;
    }    
}

std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}