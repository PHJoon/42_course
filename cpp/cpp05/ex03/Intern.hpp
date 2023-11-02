/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:08:17 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/02 15:46:50 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    private:
    public:
        Intern(void);
        Intern(const Intern& src);
        virtual ~Intern(void);
        Intern& operator=(Intern const& rhs);

        AForm *makeForm(const std::string &formName, const std::string &target);

        class InvalidFormException: public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

#endif