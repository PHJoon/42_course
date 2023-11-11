/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:57:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/10 17:01:55 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
# define Serializer_HPP

# include <iostream>
# include <string>
# include <cstdint>

typedef struct Data
{
    int data;
    Data(int data): data(data) {}
};

class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer& src);
        virtual ~Serializer(void);
        Serializer& operator=(Serializer const& rhs);
    public:

        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif