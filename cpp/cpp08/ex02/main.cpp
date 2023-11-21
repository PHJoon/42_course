/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:10:43 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/22 08:47:43 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << std::endl << "=== main test ===" << std::endl;

    std::cout << " < MutantStack > " << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << " < std::list > " << std::endl;

    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator lit = list.begin();
    std::list<int>::iterator lite = list.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    std::list<int> l(list);

    
    // std::cout << std::endl << "=== stack container ===" << std::endl;

    // MutantStack<int> ms;
    // ms.push(5);
    // ms.push(17);
    // ms.push(3);
    // ms.push(5);
    // ms.push(737);
    // ms.push(4242);
    // ms.push(-128);
    // ms.push(-30);
    // ms.push(0);
    // std::cout << "ms top: ";
    // std::cout << ms.top() << std::endl;
    // std::cout << "ms size: ";
    // std::cout << ms.size() << std::endl;
    // MutantStack<int>::iterator msIt = ms.begin();
    // MutantStack<int>::iterator msIte = ms.end();
    // ++msIt;
    // --msIt;
    // std::cout << "ms begin [ ";
    // while (msIt != msIte)
    // {
    //     std::cout << *msIt;
    //     if (msIt != msIte - 1) std::cout << " / ";
    //     ++msIt;
    // }
    // std::cout << " ] ms end" << std::endl;
    
    // MutantStack<int>::reverse_iterator msrIt = ms.rbegin();
    // MutantStack<int>::reverse_iterator msrIte = ms.rend();
    // std::cout << "ms rbegin [ ";
    // while (msrIt != msrIte)
    // {
    //     std::cout << *msrIt;
    //     if (msrIt != msrIte - 1) std::cout << " / ";
    //     ++msrIt;
    // }
    // std::cout << " ] ms rend" << std::endl;

    
    // MutantStack<int>::const_iterator mscIt = ms.cbegin();
    // MutantStack<int>::const_iterator mscIte = ms.cend();
    // std::cout << "ms cbegin [ ";
    // while (mscIt != mscIte)
    // {
    //     std::cout << *mscIt;
    //     if (mscIt != mscIte - 1) std::cout << " / ";
    //     ++mscIt;
    // }
    // std::cout << " ] ms cend" << std::endl;
    
    // MutantStack<int>::const_reverse_iterator mscrIt = ms.crbegin();
    // MutantStack<int>::const_reverse_iterator mscrIte = ms.crend();
    // std::cout << "ms crbegin [ ";
    // while (mscrIt != mscrIte)
    // {
    //     std::cout << *mscrIt;
    //     if (mscrIt != mscrIte - 1) std::cout << " / ";
    //     ++mscrIt;
    // }
    // std::cout << " ] ms crend" << std::endl;


    // std::cout << std::endl << "msatck 복사생성한 std::stack => rs" << std::endl;
    // std::stack<int> rs(ms);
    // // MutantStack<int>::iterator sit = s.begin(); // 컴파일 에러! stack은 iterator 사용못함
    // std::cout << "rs top: " << rs.top() << std::endl;
    // std::cout << "rs size: " << rs.size() << std::endl;
    // std::cout << std::boolalpha << "rs empty: " << rs.empty() << std::endl;
    // std::cout << "rs stack top [ ";
    // while (rs.size())
    // {
    //     std::cout << rs.top();
    //     rs.pop();
    //     if (rs.size() != 0) std::cout << " / ";
    // }
    // std::cout << " ] rs bottom" << std::endl;

    // std::cout << std::endl << "===  list container ===" << std::endl;
    // MutantStack<int, std::list<int> > msList;
    // // msList.push_back(24); // std::list의 멤버함수 사용하려면 따로 추가해줘야함, 지금은 std::stack을 상속받고 있기 때문에
    // msList.push(100);
    // msList.push(30);
    // msList.push(-23);
    // msList.push(4);
    // msList.push(1);
    // std::cout << "msList top: " << msList.top() << std::endl;
    // std::cout << "msList size: " << msList.size() << std::endl;
    // MutantStack<int, std::list<int> >::iterator msListIt = msList.begin();
    // MutantStack<int, std::list<int> >::iterator msListIte = msList.end();
    // std::cout << "msList begin [ ";
    // while (msListIt != msListIte)
    // {
    //     std::cout << *msListIt;
    //     MutantStack<int, std::list<int> >::iterator tmp = --(msList.end());
    //     if (msListIt != tmp) std::cout << " / ";
    //     ++msListIt;
    // }
    // std::cout << " ] msList end;" << std::endl;
    
    return 0;
}