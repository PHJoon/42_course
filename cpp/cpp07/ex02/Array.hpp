/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:29:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/12 18:54:52 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
# define Array_HPP

# include <iostream>
# include <cstddef>

template<typename T>
class Array
{
    private:
        std::size_t _arrayLen;
        T *_array;
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array& src);
        virtual ~Array(void);
        Array& operator=(Array const& rhs);

        T &operator[](unsigned int idx);

        const std::size_t size(void) const;
};

# include "Array.tpp"

#endif