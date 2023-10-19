/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:18:54 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/19 15:18:18 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int _fixed_point_num;
        static const int _fractional_bits = 8;

    public:
        Fixed(void);
        Fixed(const Fixed& src);
        ~Fixed(void);
        Fixed& operator=(Fixed const& rhs);

        Fixed(const int fixed_point_num);
        Fixed(const float fixed_point_num);
        
        float   toFloat(void) const;
        int     toInt(void) const;
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        bool operator>(Fixed const& rhs) const;
        bool operator<(Fixed const& rhs) const;
        bool operator>=(Fixed const& rhs) const;
        bool operator<=(Fixed const& rhs) const;
        bool operator==(Fixed const& rhs) const;
        bool operator!=(Fixed const& rhs) const;
        
        Fixed operator+(Fixed const& rhs) const;
        Fixed operator-(Fixed const& rhs) const;
        Fixed operator*(Fixed const& rhs) const;
        Fixed operator/(Fixed const& rhs) const;
        
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed&   min(Fixed& lhs, Fixed& rhs);
        static Fixed&   max(Fixed& lhs, Fixed& rhs);
        static Fixed const&   min(Fixed const& lhs, Fixed const& rhs);
        static Fixed const&   max(Fixed const& lhs, Fixed const& rhs);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
