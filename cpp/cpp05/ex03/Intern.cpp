/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:08:13 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/02 15:46:39 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& src)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void)src;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(Intern const& rhs)
{
    std::cout << "Intern copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        (void)rhs;
    }
    return *this;
}

AForm *makeShrubbery(const std::string &t)
{
    return new ShrubberyCreationForm(t);
}

AForm *makeRobotomy(const std::string &t)
{
    return new RobotomyRequestForm(t);
}

AForm *makePresidential(const std::string &t)
{
    return new PresidentialPardonForm(t);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    try
    {
        std::string arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
        AForm *(*f[3])(const std::string&) = {
            &makeShrubbery, &makeRobotomy, &makePresidential
        };
        
        for (int i = 0; i < 3; i++) 
        {
            if (arr[i] == formName) {
                std::cout << "Intern creates " << arr[i] << std::endl;
                return (*f[i])(target);
            }
        }
        throw InvalidFormException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return NULL;
    }
}

const char *Intern::InvalidFormException::what(void) const throw()
{
    return "Invalid Form Name!";
}
