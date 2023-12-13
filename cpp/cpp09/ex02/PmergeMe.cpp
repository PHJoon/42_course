/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/12/13 13:49:10 by hyungjpa         ###   ########.fr       */
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

int myLowerBound(std::vector<int> &arr, int len, int target)
{
    int low = 0; 
    int high = len - 1;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        
        // 검사 범위 반으로 좁혀가기
        if (target < arr[mid])
        {
            high = mid -1;
        }
        else if (target >= arr[mid])
        {
            low = mid + 1;
        }
    }
    return high + 1;
}


std::vector<int> jacobsthal(int n)
{
    std::vector<int> jacobsthalVec;

    jacobsthalVec.push_back(0);
    jacobsthalVec.push_back(1);
    jacobsthalVec.push_back(3);

    for (int i = 3; i < n; i++)
    {
        jacobsthalVec[i] = std::pow(2, jacobsthalVec[i - 1]) - jacobsthalVec[i - 1];
    }
    return jacobsthalVec;
}

typedef std::vector<std::pair<int, int>> vecPair;



std::vector<int>    mainSort(std::vector<int> &main)
{
    std::vector<int> left, right;
    
    if (main.size() == 1)
        return ;

    std::size_t mid = main.size() / 2;
    
    left = std::vector<int>(main.begin(), main.begin() + mid);
    right = std::vector<int>(main.begin() + mid, main.end());

    left = mainSort(left);
    right = mainSort(right);

    return ;
    
}

int findFromPair(vecPair &pairVec, int target)
{
    for (vecPair::iterator it = pairVec.begin(); it != pairVec.end(); it++)
    {
        if ((*it).first == target)
        {
            return (*it).second;
        }
    }
    return -1;
}

std::vector<int> pendSortByMain(std::vector<int> &main, std::vector<int> &pend, vecPair &pairVec)
{
    std::vector<int> result;

    for (vecIter it = main.begin(); it != main.end(); it++)
    {
        int pend = findFromPair(pairVec, *it);
        result.push_back(pend);
    }
    return result;
}


void    PmergeMe::execute(std::vector<int> &vec)
{
    std::size_t vecSize = vec.size();

    // 홀수배열이라면 마지막 빼고 진행 후 끝에 다시 추가
    int remain = -1;
    if (vec.size() % 2)
    {
        remain = vec.back();
        vec.pop_back();
    }

    // main , pend 나누기
    std::vector<int> main, pend;

    vecPair pairVec;

    for (vecIter it = vec.begin(); it != vec.end(); it += 2)
    {
        if (*(it) < *(it + 1))
        {
            int tmp = *(it);
            *(it) = *(it + 1);
            *(it + 1) = tmp;
        }
        
        main.push_back(*(it));
        pairVec.push_back(std::make_pair(*(it), *(it + 1)));
    }

    // main 정렬
    mergeInsertSort(main);


    // pair 보고 main에 맞춰서 pend 정렬
    pend = pendSortByMain(main, pend, pairVec);


    // main 에 pend 하나씩 삽입 jacobsthal 수에 맞춰서
    
    


    while (main.size() != vecSize)
    {
        
        
    }

    // remain 있으면
    if (remain != -1)
    {
        
    }
    
    




}