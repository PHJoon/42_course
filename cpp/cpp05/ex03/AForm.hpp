/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:45:13 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/03 13:34:24 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string   _name;
        const int   _s_grade;
        const int   _e_grade;
        bool    _signed;
    public:
        AForm(void);
        AForm(const std::string& name, const int s_grade, const int e_grade);
        AForm(const AForm& src);
        virtual ~AForm(void);
        AForm& operator=(AForm const& rhs);

        const std::string &getName(void) const;
        const int &getSignGrade(void) const;
        const int &getExecuteGrade(void) const;
        const bool &getSigned(void) const;

        void    setSigned(bool sign);
        
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

        class NotSignedException: public std::exception
        {
            public:
                const char *what(void) const throw();
        };
  
        virtual void    executeForm(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &aForm);


#endif