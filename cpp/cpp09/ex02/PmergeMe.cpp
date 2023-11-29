/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/11/29 17:15:13 by hyungjpa         ###   ########.fr       */
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



typedef std::vector<std::pair<int, int>> vecPair;


int jacobsthal(int n)
{
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int> jacobsthalVector(int n)
{
    std::vector<int> vec;
    int idx = 3;
    while (idx < n) {
        vec.push_back(jacobsthal(idx));
        idx++;
    }
    return vec;
}


void    sort(std::vector<int> vec)
{
    if (vec.size() == 1) return;
    
    int straggler = -1;
    if (vec.size() % 2) {
        straggler = vec.back();
        vec.pop_back();
    }

    vecPair pairVec;
    for (vecIter it = vec.begin(); it != vec.end(); it + 2) {
        pairVec.push_back(std::make_pair(*it, *(it + 1)));
    }

    // pair 내부 largest element swap
    for (vecPair::iterator it = pairVec.begin(); it != pairVec.end(); it++) {
        if ((*it).first < (*it).second) {
            int tmp = (*it).first;
            (*it).first = (*it).second;
            (*it).second = tmp;
        }
    }

    int half = vec.size() / 2;
    sort(std::vector<int>(vec.begin(), vec.begin() + half));
    sort(std::vector<int>(vec.begin() + half, vec.end()));
    
}

// 반씩 나누면서 재귀 들어가기

// 다시 b 정렬하기

void    PmergeMe::execute(void)
{
    // straggler 찾기 홀수배열이라면 마지막 빼고 진행 후 끝에 다시 추가
    int straggler = -1;
    if (_beforeVec.size() % 2) {
        straggler = _beforeVec.back();
        _beforeVec.pop_back();
    }

    // pair vector로 만들기
    vecPair pairVec;
    for (vecIter it = _beforeVec.begin(); it != _beforeVec.end(); it + 2) {
        pairVec.push_back(std::make_pair(*it, *(it + 1)));
    }

    // pair 내부 largest element swap
    for (vecPair::iterator it = pairVec.begin(); it != pairVec.end(); it++) {
        if ((*it).first < (*it).second) {
            int tmp = (*it).first;
            (*it).first = (*it).second;
            (*it).second = tmp;
        }
    }
    
    // pair vector first sorting
    

    

    // 큰 값 main, 작은 값 pend
    std::vector<int> main;
    std::vector<int> pend;

    for (vecPair::iterator it = pairVec.begin(); it != pairVec.end(); it++) {
        main.push_back((*it).first);
        pend.push_back((*it).second);
    }

    // 



}