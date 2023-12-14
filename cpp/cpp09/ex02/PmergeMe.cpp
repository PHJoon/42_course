/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:49:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/12/14 10:56:27 by hyungjpa         ###   ########.fr       */
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

    // 정렬
    std::clock_t startV, finishV, startL, finishL;

    startV = clock();
    setOriginVec(ac, av);
    _jacobsthalVec = jacobsthalVector(30);
    VEC v(_originVec);
    _sortedVec = fordJohnsonVector(v);
    finishV = clock();

    startL = clock();
    setOriginList(ac, av);
    _jacobsthalList = jacobsthalList(30);
    LIST l(_originList);
    _sortedList = fordJohnsonList(l);
    finishL = clock();


    _vecDuration = static_cast<double>(finishV - startV) / CLOCKS_PER_SEC;
    _listDuration = static_cast<double>(finishL - startL) / CLOCKS_PER_SEC;

    std::cout << "before:  ";
    displayVector(_originVec);
    std::cout << "after:   ";
    displayVector(_sortedVec);
    
    // std::cout << "before:  ";
    // displayList(_originList);
    // std::cout << "after:   ";
    // displayList(_sortedList);

    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << _originVec.size() <<  " elements with std::vector : "
    << _vecDuration << "s" << std::endl;
    
    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << _originList.size() <<  " elements with std::list : "
    << _listDuration << "s" << std::endl;

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
    return *this;
}

bool PmergeMe::checkArgs(int ac, char **av)
{
    // 숫자 체크
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

    // 양수, int_max 범위 체크
    for (int i = 1; i < ac; i++)
    {
        long long   tmp = std::atoll(av[i]);
        if (tmp <= 0 || tmp > std::numeric_limits<int>::max())
        {
            return false;
        }
    }

    return true;
}

void PmergeMe::setOriginVec(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        _originVec.push_back(std::atoi(av[i]));
    }
}

void PmergeMe::setOriginList(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        _originList.push_back(std::atoi(av[i]));
    }
}

// -------------------------------------------------- VECTOR --------------------------------------------------
void PmergeMe::displayVector(VEC &v)
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

// 이진 탐색으로 삽입 위치 찾기 (target보다 큰 가장 작은 정수 값)
int PmergeMe::myLowerBoundVector(VEC &v, int len, int target)
{
    int low = 0;
    int high = len - 1;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (target < v[mid])
        {
            high = mid - 1;
        }
        else if (target >= v[mid])
        {
            low = mid + 1;
        }
    }
    return high + 1;
}

// 야콥스탈 수열 생성기
VEC PmergeMe::jacobsthalVector(int n)
{
    VEC jacobsthalVec;

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

// pair에서 짝지어진 작은 값 찾기
int PmergeMe::findFromPairVector(VECPAIR &pairVec, int target)
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

// 정렬된 main에 맞춰 pend도 정렬
VEC PmergeMe::pendSortByMainVector(VEC &mainChain, VECPAIR &pairVec)
{
    VEC result;

    for (VECITER it = mainChain.begin(); it != mainChain.end(); it++)
    {
        int pending = findFromPairVector(pairVec, *it);
        result.push_back(pending);
    }
    return result;
}

// FordJohnson
VEC PmergeMe::fordJohnsonVector(VEC &v)
{
    std::size_t vecSize = v.size();

    if (vecSize == 1)
        return v;

    // 길이가 홀수라면 마지막 숫자 따로 빼놓고 맨 마지막에 삽입
    int remain = -1;
    if (vecSize % 2)
    {
        remain = v.back();
        v.pop_back();
    }

    // 두 개씩 짝지어서 큰 수는 main으로, pair만들어서 pair배열로
    VEC mainChain, pending;
    VECPAIR pairVec;

    for (VECITER it = v.begin(); it != v.end(); it += 2)
    {
        if (*(it) < *(it + 1))
        {
            int tmp = *(it);
            *(it) = *(it + 1);
            *(it + 1) = tmp;
        }
        
        mainChain.push_back(*(it));
        pairVec.push_back(std::make_pair(*(it), *(it + 1)));
    }

    // main만 다시 재귀적으로 정렬
    
    // std::cout << "main\n";
    // displayVector(mainChain);
    // std::cout << "main start\n";
    mainChain = fordJohnsonVector(mainChain);
    // std::cout << "\nmain end\n";

    // 정렬된 main에 맞춰 pend도 정렬
    pending = pendSortByMainVector(mainChain, pairVec);

    // main을 result 배열에 삽입(main은 이미 정렬되어 있음)
    // pend를 하나씩 야콥스탈 수에 맞춰서 result에 삽입(최소한의 탐색을 위해)

    // std::cout << "main\n";
    // displayVector(mainChain);
    // std::cout << "pend\n";
    // displayVector(pending);
    VEC result;

    result.push_back(pending[0]);
    result.push_back(mainChain[0]);

    for (std::size_t i = 1; i < vecSize; i++)
    {
        int jac1 = _jacobsthalVec[i - 1] - 1;
        int jac2 = _jacobsthalVec[i] - 1;

        if (jac1 > static_cast<int>(pending.size()) - 1)
        {
            break;
        }

        if (jac2 > static_cast<int>(pending.size()) - 1)
        {
            jac2 = static_cast<int>(pending.size()) - 1;
        }

        for (int j = jac1 + 1; j <= jac2; j++)
        {
            result.push_back(mainChain[j]);
            // std::cout << "result\n";
            // displayVector(result);
        }
        for (int k = jac2; k > jac1; k--)
        {
            int position = myLowerBoundVector(result, result.size(), pending[k]);
            result.insert(result.begin() + position, pending[k]);
            // std::cout << "result\n";
            // displayVector(result);
        }
    }

    // 처음에 빼둔 remain 삽입
    if (remain != -1)
    {
        // std::cout << "remain\n";
        // std::cout << remain << std::endl;
        int position = myLowerBoundVector(result, result.size(), remain);
        result.insert(result.begin() + position, remain);
    }

    // std::cout << "result\n";
    // displayVector(result);
    return result;
}

// -------------------------------------------------- LIST --------------------------------------------------
void PmergeMe::displayList(LIST &l)
{
    for (LISTITER it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it;
        LISTITER tmp = it;
        if (++tmp == l.end())
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " ";
        }
    }
}

// 이진 탐색으로 삽입 위치 찾기 (target보다 큰 가장 작은 정수 값)
int PmergeMe::myLowerBoundList(LIST &l, int len, int target)
{
    int low = 0;
    int high = len - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        LISTITER tmp = l.begin();
        std::advance(tmp, mid);
        if (target < *tmp)
        {
            high = mid - 1;
        }
        else if (target >= *tmp)
        {
            low = mid + 1;
        }
    }
    return high + 1;
}

// 야콥스탈 수열 생성기
LIST PmergeMe::jacobsthalList(int n)
{
    LIST jacobsthalLst;
    
    jacobsthalLst.push_back(1);
    jacobsthalLst.push_back(3);
    
    for (int i = 2; i < n; i++)
    {
        int next;
        LISTITER tmp = jacobsthalLst.begin();
        std::advance(tmp, i - 1);
        if (i % 2)
        {
            next = 2 * (*tmp) + 1;
        }
        else
        {
            next = 2 * (*tmp) - 1;
        }
        jacobsthalLst.push_back(next);
    }
    return jacobsthalLst;
}

// pair에서 짝지어진 작은 값 찾기
int PmergeMe::findFromPairList(LISTPAIR &pairList, int target)
{
    for (LISTPAIRITER it = pairList.begin(); it != pairList.end(); it++)
    {
        if ((*it).first == target)
        {
            return (*it).second;
        }
    }
    return -1;
}

// 정렬된 main에 맞춰 pend도 정렬
LIST PmergeMe::pendSortByMainList(LIST &mainChain, LISTPAIR &pairList)
{
    LIST result;

    for (LISTITER it = mainChain.begin(); it != mainChain.end(); it++)
    {
        int pending = findFromPairList(pairList, *it);
        result.push_back(pending);
    }
    return result;
}

// FordJohnson
LIST PmergeMe::fordJohnsonList(LIST &l)
{
    std::size_t listSize = l.size();

    if (listSize == 1)
        return l;
    
    // 길이가 홀수라면 마지막 숫자 따로 빼놓고 맨 마지막에 삽입
    int remain = -1;
    if (listSize % 2)
    {
        remain = l.back();
        l.pop_back();
    }
    
    // 두 개씩 짝지어서 큰 수는 main으로, pair만들어서 pair배열로
    LIST mainChain, pending;
    LISTPAIR pairList;

    for (LISTITER it = l.begin(); it != l.end();)
    {
        LISTITER tmp = it;
        if (*(it) < *(++tmp))
        {
            int temp = *(it);
            *(it) = *tmp;
            *(tmp) = temp;
        }
        mainChain.push_back(*(it));
        pairList.push_back(std::make_pair(*(it), *(tmp)));
        ++it;
        ++it;
    }
    
    // main만 다시 재귀적으로 정렬
    mainChain = fordJohnsonList(mainChain);

    // 정렬된 main에 맞춰 pend도 정렬
    pending = pendSortByMainList(mainChain, pairList);

    // main을 result 배열에 삽입(main은 이미 정렬되어 있음)
    // pend를 하나씩 야콥스탈 수에 맞춰서 result에 삽입(최소한의 탐색을 위해)

    LIST result;

    result.push_back(pending.front());
    result.push_back(mainChain.front());

    for (std::size_t i = 1; i < listSize; i++)
    {
        LISTITER it1 = _jacobsthalList.begin();
        LISTITER it2 = _jacobsthalList.begin();

        std::advance(it1, i - 1);
        std::advance(it2, i);
        int jac1 = *(it1) - 1;
        int jac2 = *(it2) - 1;

        if (jac1 > static_cast<int>(pending.size()) - 1)
        {
            break;
        }

        if (jac2 > static_cast<int>(pending.size()) - 1)
        {
            jac2 = static_cast<int>(pending.size()) - 1;
        }

        for (int j = jac1 + 1; j <= jac2; j++)
        {
            LISTITER tmpM = mainChain.begin();
            std::advance(tmpM, j);
            result.push_back(*tmpM);
        }
        for (int k = jac2; k > jac1; k--)
        {
            LISTITER tmpP = pending.begin();
            std::advance(tmpP, k);
            int position = myLowerBoundList(result, result.size(), *tmpP);
            LISTITER tmpR = result.begin();
            std::advance(tmpR, position);
            result.insert(tmpR, *tmpP);
        }
    }

    // 처음에 빼둔 remain 삽입
    if (remain != -1)
    {
        int position = myLowerBoundList(result, result.size(), remain);
        LISTITER tmpR2 = result.begin();
        std::advance(tmpR2, position);
        result.insert(tmpR2, remain);
    }
    
    return result;
}