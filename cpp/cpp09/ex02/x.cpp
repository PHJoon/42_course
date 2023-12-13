#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

typedef std::vector<int> VEC;
typedef std::vector<int>::iterator VECITER;
typedef std::vector<std::pair<int, int> > vecPair;
typedef std::vector<int>::iterator vecIter;

void display(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << (i == v.size() - 1 ? "\n" : " | ");
    }
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

std::vector<int> pendSortByMain(std::vector<int> &main, vecPair &pairVec)
{
    std::vector<int> result;

    for (vecIter it = main.begin(); it != main.end(); it++)
    {
        int pend = findFromPair(pairVec, *it);
        result.push_back(pend);
    }
    return result;
}



std::vector<int> jacob = jacobsthal(20);

std::vector<int>    fordJohnson(std::vector<int> &vec)
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
    std::cout << "\nmain Start\n";
    main = fordJohnson(main);
    std::cout << "\nmain End\n";


    // pair 보고 main에 맞춰서 pend 정렬
    pend = pendSortByMain(main, pairVec);


    // main 에 pend 하나씩 삽입 jacobsthal 수에 맞춰서

    std::cout << "main: \n";
    display(main);
    std::cout << "pend: \n";
    display(pend);


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

    std::cout << "result: \n";
    display(result);

    return result;
}



int main()
{
    std::vector<int> v;
    v.push_back(12);
    v.push_back(5);
    v.push_back(7);
    v.push_back(4);
    v.push_back(1);
    v.push_back(9);
    v.push_back(21);
    v.push_back(3);
    v.push_back(8);
    v.push_back(100);
    v.push_back(87);
    v.push_back(11);
    v.push_back(25);
    v.push_back(45);
    v.push_back(78);
    v.push_back(65);
    v.push_back(1023);
    v.push_back(329);
    v.push_back(48);
    v.push_back(52);
    v.push_back(60);
    v.push_back(109);
    v.push_back(278);


    std::cout << "before\n";
    display(v);


    std::cout << "after\n";

    std::vector<int> a;

    a = fordJohnson(v);
    display(a);


}
