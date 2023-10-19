/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:18:54 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/19 09:59:29 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>

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

        int getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
