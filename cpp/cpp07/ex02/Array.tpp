/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:32:17 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/12 18:55:54 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

Array::Array<T>(void)
{
    
}
        Array(unsigned int n);
        Array(const Array& src);
        virtual ~Array(void);
        Array& operator=(Array const& rhs);

        T &operator[](unsigned int idx);

        const std::size_t size(void) const;