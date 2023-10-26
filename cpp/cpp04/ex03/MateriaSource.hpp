/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:27:12 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 11:35:29 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_HPP
# define MateriaSource_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria *_source[4];
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& src);
        virtual ~MateriaSource(void);
        MateriaSource& operator=(MateriaSource const& rhs);

        virtual void learnMateria(AMateria *);
        virtual AMateria *createMateria(std::string const &type);
};

#endif