/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/12/13 18:13:42 by hyungjpa         ###   ########.fr       */
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

void PmergeMe::display(VEC &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << (i == v.size() - 1 ? "\n" : " | ");
    }
}


int PmergeMe::myLowerBound(VEC &arr, int len, int target)
{
    int low = 0; 
    int high = len - 1;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // 검사 범위 반으로 좁혀가기
        if (target < arr[mid])
        {
            high = mid - 1;
        }
        else if (target >= arr[mid])
        {
            low = mid + 1;
        }
    }
    return high + 1;
}

VEC jacobsthal(int n)
{
    std::vector<int> jacobsthalVec;

    jacobsthalVec.push_back(1);
    jacobsthalVec.push_back(3);

    for (int i = 2; i < n; i++)
    {
        int next;
        if (i % 2)
        {
            next = 2 * jacobsthalVec[i - 1] + 1;
        }
        else
        {
            next = 2 * jacobsthalVec[i - 1] - 1;
        }
        jacobsthalVec.push_back(next);
    }
    return jacobsthalVec;
}

int PmergeMe::findFromPair(VECPAIR &pairVec, int target)
{
    for (VECPAIRITER it = pairVec.begin(); it != pairVec.end(); it++)
    {
        if ((*it).first == target)
        {
            return (*it).second;
        }
    }
    return -1;
}

VEC PmergeMe::pendSortByMain(VEC &main, VECPAIR &pairVec)
{
    VEC result;

    for (VECITER it = main.begin(); it != main.end(); it++)
    {
        int pend = findFromPair(pairVec, *it);
        result.push_back(pend);
    }
    return result;
}

VEC jacob = jacobsthal(20);

VEC PmergeMe::fordJohnson(VEC &vec)
{
    std::size_t vecSize = vec.size();

    if (vec.size() == 1)
        return vec;

    display(vec);

    // 홀수배열이라면 마지막 빼고 진행 후 끝에 다시 추가
    int remain = -1;
    if (vec.size() % 2)
    {
        remain = vec.back();
        vec.pop_back();
    }

    std::cout << "remain: " << remain << std::endl;
    // main , pend 나누기
    std::vector<int> main, pend;

    VECPAIR pairVec;

    for (VECITER it = vec.begin(); it != vec.end(); it += 2)
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
    // std::cout << "\nmain Start\n";

    main = fordJohnson(main);

    // std::cout << "\nmain End\n";

    // pair 보고 main에 맞춰서 pend 정렬
    pend = pendSortByMain(main, pairVec);


    // main 에 pend 하나씩 삽입 jacobsthal 수에 맞춰서

    // std::cout << "main: \n";
    // display(main);
    // std::cout << "pend: \n";
    // display(pend);


    std::vector<int> result;


    result.push_back(pend[0]);
    result.push_back(main[0]);

    for (int i = 1; i < vecSize; i++)
    {
        int jac1 = jacob[i - 1] - 1;
        int jac2 = jacob[i] - 1;

        if (jac1 > pend.size() - 1)
        {
            break;
        }

        if (jac2 > pend.size() - 1)
        {
            jac2 = pend.size() - 1;
        }

        for (int j = jac1 + 1; j <= jac2; j++)
        {
            result.push_back(main[j]);
            std::cout << "result: " << std::endl;
            display(result);
        }
        for (int k = jac2; k > jac1; k--)
        {
            int position = myLowerBound(result, result.size(), pend[k]);
            result.insert(result.begin() + position, pend[k]);
        }
    }

    // remain 있으면
    if (remain != -1)
    {
        int position = myLowerBound(result, result.size(), remain);
        result.insert(result.begin() + position, remain);
    }

    // std::cout << "result: \n";
    // display(result);

    return result;
}