/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:57:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/10 16:55:52 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer& src)
{
    (void)src;
}

Serializer::~Serializer(void)
{
}

Serializer& Serializer::operator=(Serializer const& rhs)
{
    (void)rhs;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t ret;
    ret = reinterpret_cast<uintptr_t>(ptr);
    return ret;
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *ret;
    ret = reinterpret_cast<Data *>(raw);
    return ret;
}