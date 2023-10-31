/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:17:20 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/31 15:29:07 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
    private:
        const std::string   _name;
        int _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat& src);
        virtual ~Bureaucrat(void);
        Bureaucrat& operator=(Bureaucrat const& rhs);

        const   std::string &getName(void) const;
        const int &getGrade(void) const;

        void    increment(void);
        void    decrement(void);

        class GradeTooHighException: public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif