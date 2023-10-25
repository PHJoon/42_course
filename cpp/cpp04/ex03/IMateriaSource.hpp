/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:36:26 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 15:20:28 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMateriaSource_HPP
# define IMateriaSource_HPP

# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
    private:
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria *) = 0;
        virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
