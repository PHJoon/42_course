/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:17:22 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/02 13:06:56 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void a()
{
    system("leaks a.out");
}

int main()
{
    atexit(a);
    std::cout << "--- TEST START ---" << std::endl << std::endl;

    std::cout << "--- name: A / grade: 1 ---" << std::endl;
    try
    {
        AForm *sh = new ShrubberyCreationForm("Home");
        AForm *rb = new RobotomyRequestForm("Secretary");
        AForm *pr = new PresidentialPardonForm("Minister");

        Bureaucrat *a = new Bureaucrat("A", 1);
        
        std::cout << std::endl << "--- main ---" << std::endl;

        std::cout << *sh << std::endl;
        std::cout << *rb << std::endl;
        std::cout << *pr << std::endl;
        a->signForm(*sh);
        a->signForm(*rb);
        a->signForm(*pr);
        std::cout << *sh << std::endl;
        std::cout << *rb << std::endl;
        std::cout << *pr << std::endl;

        a->executeForm(*sh);
        a->executeForm(*rb);
        a->executeForm(*pr);

        std::cout << "--- end ---" << std::endl << std::endl;

        delete sh;
        delete rb;
        delete pr;
        delete a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // std::cout << std::endl << "--- name: A / grade: 25 ---" << std::endl;
    // try
    // {
    //     AForm *sh = new ShrubberyCreationForm("Home");
    //     AForm *rb = new RobotomyRequestForm("Secretary");
    //     AForm *pr = new PresidentialPardonForm("Minister");

    //     Bureaucrat *a = new Bureaucrat("A", 25);
        
    //     std::cout << std::endl << "--- main ---" << std::endl;
        
    //     std::cout << *sh << std::endl;
    //     std::cout << *rb << std::endl;
    //     std::cout << *pr << std::endl;
    //     a->signForm(*sh);
    //     a->signForm(*rb);
    //     a->signForm(*pr);
    //     std::cout << *sh << std::endl;
    //     std::cout << *rb << std::endl;
    //     std::cout << *pr << std::endl;

    //     a->executeForm(*sh);
    //     a->executeForm(*rb);
    //     a->executeForm(*pr);

    //     std::cout << "--- end ---" << std::endl << std::endl;
    //     delete sh;
    //     delete rb;
    //     delete pr;
    //     delete a;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    // std::cout << std::endl << "--- name: A / grade: 72 ---" << std::endl;
    // try
    // {
    //     AForm *sh = new ShrubberyCreationForm("Home");
    //     AForm *rb = new RobotomyRequestForm("Secretary");
    //     AForm *pr = new PresidentialPardonForm("Minister");

    //     Bureaucrat *a = new Bureaucrat("A", 72);
        
    //     std::cout << std::endl << "--- main ---" << std::endl;

    //     std::cout << *sh << std::endl;
    //     std::cout << *rb << std::endl;
    //     std::cout << *pr << std::endl;
    //     a->signForm(*sh);
    //     a->signForm(*rb);
    //     a->signForm(*pr);
    //     std::cout << *sh << std::endl;
    //     std::cout << *rb << std::endl;
    //     std::cout << *pr << std::endl;

    //     a->executeForm(*sh);
    //     a->executeForm(*rb);
    //     a->executeForm(*pr);

    //     std::cout << "--- end ---" << std::endl << std::endl;

    //     delete sh;
    //     delete rb;
    //     delete pr;
    //     delete a;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    // std::cout << std::endl << "--- name: A / grade: 145 ---" << std::endl;
    // try
    // {
    //     AForm *sh = new ShrubberyCreationForm("Home");
    //     AForm *rb = new RobotomyRequestForm("Secretary");
    //     AForm *pr = new PresidentialPardonForm("Minister");

    //     Bureaucrat *a = new Bureaucrat("A", 145);
        
    //     std::cout << std::endl << "--- main ---" << std::endl;

    //     std::cout << *sh << std::endl;
    //     std::cout << *rb << std::endl;
    //     std::cout << *pr << std::endl;
    //     a->signForm(*sh);
    //     a->signForm(*rb);
    //     a->signForm(*pr);
    //     std::cout << *sh << std::endl;
    //     std::cout << *rb << std::endl;
    //     std::cout << *pr << std::endl;

    //     a->executeForm(*sh);
    //     a->executeForm(*rb);
    //     a->executeForm(*pr);

    //     std::cout << "--- end ---" << std::endl << std::endl;

    //     delete sh;
    //     delete rb;
    //     delete pr;
    //     delete a;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    // std::cout << std::endl << "--- name: A / grade: 150 ---" << std::endl;
    // try
    // {
    //     AForm *sh = new ShrubberyCreationForm("Home");
    //     AForm *rb = new RobotomyRequestForm("Secretary");
    //     AForm *pr = new PresidentialPardonForm("Minister");

    //     Bureaucrat *a = new Bureaucrat("A", 150);
        
    //     std::cout << std::endl << "--- main ---" << std::endl;

    //     std::cout << *sh << std::endl;
    //     std::cout << *rb << std::endl;
    //     std::cout << *pr << std::endl;
    //     a->signForm(*sh);
    //     a->signForm(*rb);
    //     a->signForm(*pr);
    //     std::cout << *sh << std::endl;
    //     std::cout << *rb << std::endl;
    //     std::cout << *pr << std::endl;

    //     a->executeForm(*sh);
    //     a->executeForm(*rb);
    //     a->executeForm(*pr);

    //     std::cout << "--- end ---" << std::endl << std::endl;

    //     delete sh;
    //     delete rb;
    //     delete pr;
    //     delete a;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }


    std::cout << std::endl << "--- TEST END ---" << std::endl;

    return 0;
}