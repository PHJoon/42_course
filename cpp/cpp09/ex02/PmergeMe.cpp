/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/28 13:11:43 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs)
{
    if (this != &rhs)
    {
    }
    return *this;
}

bool    PmergeMe::setBefore(int ac, const char **argv)
{
    long long tmp;
    for (int i = 1; i < ac; i++) {
        tmp = std::atoll(argv[i]);
        if (tmp < 0 || tmp > std::numeric_limits<int>::max()) {
            return false;
        } else {
            _before.push_back(static_cast<int>(tmp));
        }
    }
    return true;
}



void    PmergeMe::execute(void)
{
    // straggler 찾기 홀수배열이라면 마지막 빼고 진행 후 끝에 다시 추가
    int straggler = -1;
    if (_before.size() % 2) {
        straggler = _before.back();
        _before.pop_back();
    }
    
    // pairs로 나누기
    std::vector<std::pair<int, int>> tmp;

    for (std::vector<int>::iterator iter = _before.begin(); iter != _before.end(); iter++) {
        tmp.push_back(std::make_pair(*iter, *(++iter)));
    }
    
    // pair sorting
    for (std::vector<std::pair<int, int>>::iterator iter = tmp.begin(); iter != tmp.end(); iter++) {
        if ((*iter).first < (*iter).second) {
            int temp = (*iter).first;
            (*iter).first = (*iter).second;
            (*iter).second = temp;
        }   
    }
    
    // 큰 값 main, 작은 값 pend
    

    // 



}