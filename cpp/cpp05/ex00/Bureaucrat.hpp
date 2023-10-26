/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:17:20 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/10/26 16:21:59 by hyungjpa         ###   ########.fr       */
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
};

#endif