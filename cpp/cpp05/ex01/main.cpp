/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:17:22 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/02 13:05:47 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void a()
{
    system("leaks a.out");
}

int main()
{
    atexit(a);
    std::cout << "--- TEST START ---" << std::endl << std::endl;

    std::cout << "--- name: FormA / s_grade: 151 / e_grade: 1 ---" << std::endl;
    try
    {
        Form fa = Form("FormA", 151, 1);
        std::cout << fa << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl << "--- name: FormB / s_grade: 1 / e_grade: 151 ---" << std::endl;
    try
    {
        Form fb = Form("FormB", 1, 151);
        std::cout << fb << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl << "--- name: FormC / s_grade: 1 / e_grade: 10 ---" << std::endl;
    std::cout << "--- name: FormD / s_grade: 1 / e_grade: 10 ---" << std::endl;
    std::cout << "--- name: A / grade: 1 ---" << std::endl;
    try
    {
        Form fc = Form("FormC", 1, 10);
        Form fd = Form("FormD", 1, 10);
        std::cout << fc << std::endl;
        Bureaucrat a = Bureaucrat("A", 1);
        a.signForm(fc);
        std::cout << fc << std::endl;
        a.decrement();
        std::cout << fd << std::endl;
        a.signForm(fd);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl << "--- name: FormC / s_grade: 150 / e_grade: 10 ---" << std::endl;
    std::cout << "--- name: FormD / s_grade: 149 / e_grade: 10 ---" << std::endl;
    std::cout << "--- name: B / grade: 150 ---" << std::endl;
    try
    {
        Form fe = Form("FormE", 150, 10);
        Form ff = Form("FormF", 149, 10);
        std::cout << fe << std::endl;
        Bureaucrat b = Bureaucrat("B", 150);
        b.signForm(fe);
        std::cout << fe << std::endl;
        std::cout << ff << std::endl;
        b.signForm(ff);
        b.increment();
        b.signForm(fe);
        std::cout << fe << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    std::cout << std::endl << "--- TEST END ---" << std::endl;

    return 0;
}