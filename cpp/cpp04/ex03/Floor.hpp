/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:31:52 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 16:06:00 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Floor_HPP
# define Floor_HPP

# include "AMateria.hpp"
# include <iostream>

class Floor
{
    private:
        AMateria *_floor[4];
        int _size;
        
    public:
        Floor(void);
        Floor(const Floor& src);
        virtual ~Floor(void);
        Floor& operator=(Floor const& rhs);

        void    putFloor(AMateria *);
        void    showFloor(void) const;
};

#endif