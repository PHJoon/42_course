/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:24:14 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/25 11:26:17 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_HPP
# define AMateria_HPP

# include <iostream>
# include <string>

class AMateria
{
    protected:
    public:
        AMateria(void);
        AMateria(const AMateria& src);
        virtual ~AMateria(void);
        AMateria& operator=(AMateria const& rhs);

        AMateria(std::string const &type);
        
        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif