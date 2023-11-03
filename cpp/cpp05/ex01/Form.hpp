/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:20:15 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/03 13:13:14 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
# define Form_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string   _name;
        const int   _s_grade;
        const int   _e_grade;
        bool    _signed;
    public:
        Form(void);
        Form(const std::string& name, const int s_grade, const int e_grade);
        Form(const Form& src);
        virtual ~Form(void);
        Form& operator=(Form const& rhs);

        const std::string &getName(void) const;
        const int &getSignGrade(void) const;
        const int &getExecuteGrade(void) const;
        const bool &getSigned(void) const;

        void    beSigned(const Bureaucrat &bureaucrat);
        
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

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif