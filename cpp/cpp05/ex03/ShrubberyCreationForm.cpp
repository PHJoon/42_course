/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:59:57 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/03 13:40:04 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shruberry", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm target: " << _target << " constructor called" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm("Shrubbery", 145, 137), _target(src._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    this->setSigned(src.getSigned());
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
 std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _target = rhs._target;
        this->setSigned(rhs.getSigned());
    }
    return *this;
}

void    ShrubberyCreationForm::executeForm(Bureaucrat const &executor) const
{
    if (!this->getSigned()) throw NotSignedException();
    else {
        if (executor.getGrade() <= this->getExecuteGrade()) {
            std::ofstream   outfile;
            std::string fileName = _target + "_shrubbery";

            const std::string ret = "                            .\n"
                                    "             .              .              ;%\n"
                                    "               ,           ,                :;%  %;\n"
                                    "                :         ;                   :;%;'     .,\n"
                                    "       ,.        %;     %;            ;        %;'    ,;\n"
                                    "         ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
                                    "          %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
                                    "           ;%;      %;        ;%;        % ;%;  ,%;'\n"
                                    "            `%;.     ;%;     %;'         `;%%;.%;'\n"
                                    "             `:;%.    ;%%. %@;        %; ;@%;%'\n"
                                    "                `:%;.  :;bd%;          %;@%;'\n"
                                    "                  `@%:.  :;%.         ;@@%;'   \n"
                                    "                    `@%.  `;@%.      ;@@%;         \n"
                                    "                      `@%%. `@%%    ;@@%;        \n"
                                    "                        ;@%. :@%%  %@@%;       \n"
                                    "                          %@bd%%%bd%%:;     \n"
                                    "                            #@%%%%%:;;\n"
                                    "                            %@@%%%::;\n"
                                    "                            %@@@%(o);  . '\n"
                                    "                            %@@@o%;:(.,'\n"
                                    "                        `.. %@@@o%::;\n"
                                    "                           `)@@@o%::;\n"
                                    "                            %@@(o)::;\n"
                                    "                           .%@@@@%::;\n"
                                    "                           ;%@@@@%::;.\n"
                                    "                          ;%@@@@%%:;;;.\n"
                                    "                      ...;%@@@@@%%:;;;;,..    Gilo97";

            std::cout << executor.getName() << " executed " << this->getName() << std::endl;

            outfile.open(fileName.c_str());
            if (outfile.is_open()) {
                outfile << ret;
                outfile.close();
            } else {
                std::cout << "outfile open error" << std::endl;
            }
        } else throw GradeTooLowException();
    }
}
