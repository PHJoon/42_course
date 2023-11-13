/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:29:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/14 07:44:25 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
# define Array_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array& src);
        ~Array(void);
        Array& operator=(Array const& rhs);

        T &operator[](unsigned int idx);
        const T &operator[](unsigned int idx) const;

        unsigned int size(void) const;

        class OutOfBounds: public std::exception
        {
            public:
                const char *what(void) const throw()
                {
                    return "Out of bounds";
                }
        };
        
};

# include "Array.tpp"

#endif