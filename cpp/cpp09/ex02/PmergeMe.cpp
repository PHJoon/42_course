/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/12/13 19:44:45 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(int ac, char **av)
{
// 예외처리
    if (!checkArgs(ac, av))
    {
        throw InvalidArgsException();
    }

// 정렬 실행
    clock_t start, finish;

    VEC v(_originVec);
    start = clock();
    _sorteVec = fordJohnson(v);
    finish = clock();

    _vecDuration = static_cast<double>(finish - start) / 1000000;

    std::cout << "before: ";
    display(_originVec);
    std::cout << "after:  ";
    display(_sorteVec);

    std::cout << _vecDuration << std::endl;
    
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
    (void)src;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs)
{
    (void)rhs;
    // if (this != &rhs)
    // {
    // }
    return *this;
}

void PmergeMe::display(VEC &v)
{
    for (std::size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i];
        if (i == v.size() - 1)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " ";
        }
    }
}

bool PmergeMe::checkArgs(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string tmp(av[i]);
        for (std::size_t i = 0; i < tmp.length(); i++) 
        {
            if (!std::isdigit(tmp[i]))
            {
                return false;
            }
        }
    }

    for (int i = 1; i < ac; i++)
    {
        long long   tmp = std::atoll(av[i]);
        std::cout << tmp << std::endl;
        if (tmp <= 0 || tmp > std::numeric_limits<int>::max())
        {
            return false;
        }
        else
        {
            _originVec.push_back(static_cast<int>(tmp));
        }
    }

    std::set<int>    vecToSet(_originVec.begin(), _originVec.end());
    if (vecToSet.size() != _originVec.size())
    {
        return false;
    }
    return true;
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


    // 홀수배열이라면 마지막 빼고 진행 후 끝에 다시 추가
    int remain = -1;
    if (vec.size() % 2)
    {
        remain = vec.back();
        vec.pop_back();
    }

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

    for (std::size_t i = 1; i < vecSize; i++)
    {
        int jac1 = jacob[i - 1] - 1;
        int jac2 = jacob[i] - 1;

        if (jac1 > (int)pend.size() - 1)
        {
            break;
        }

        if (jac2 > (int)pend.size() - 1)
        {
            jac2 = (int)pend.size() - 1;
        }

        for (int j = jac1 + 1; j <= jac2; j++)
        {
            result.push_back(main[j]);
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