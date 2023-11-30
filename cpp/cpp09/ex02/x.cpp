#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

typedef std::vector<int> vec;
typedef std::vector<int>::iterator vecIter;

typedef std::vector<std::pair<int, int> > vecPair;



vecPair sortedPair;

int binarySearch(int element, )


int biSearchUpperBound(vec v, int s, int e, int find)
{
    int m;
    while (s < e) {
        m = (s + e) / 2;
        if (find >= v[m]) s = m + 1;
        else e = m;
    }
    return e;
}

void    binaryInsertion(int find, int findPair) {
    int size = sortedPair.size();
    for (int i = 1; i < size; i++)
    {
        int key = v[i];
        int pos = biSearchUpperBound(v, 0, i, key);
        std::move(v.begin() + pos, v.begin() + i, v.begin() + pos + 1);
        v[pos] = key;
    }
}



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

vec jacob = jacobsthalVector(25);

void    sort(vec v,  vecIter first, vecIter last, int x)
{
    std::ptrdiff_t len = std::distance(first, last);


    std::cout << "x = " << x << "  vector => ";
    for (vecIter it = first; it != last; it++)
    {
        std::cout << *it << (it != last - 1 ? " / " : "");
    }
    std::cout << "\n";

    vecIter s;
    vecIter e;
    if (len % x) {
        e = last;
        last -= x / 2;
        s = last;
        std::cout << *s << " " << *e << std::endl;
    }

    for (vecIter it = first; it != last; it += x) {
        if (*it < *(it + (x / 2))) {
            for (vecIter tmpIt = it; tmpIt != it + (x / 2); tmpIt++) {
                std::iter_swap(tmpIt, (tmpIt + (x / 2)));
            }
        }
    }
    
    if (len < x * 3) return;

    std::ptrdiff_t tmpLen = std::distance(first, last);
    if ((tmpLen / x) % 2) {
        last -= x;
        tmpLen -= x;
        s -= x;
    }


    sort(v, first, first + tmpLen / 2, x * 2);
    sort(v, first + tmpLen / 2, last, x * 2);


    // binary insertion pair


    std::cout << "after sort x = " << x << "  vector => ";
    for (vecIter it = first; it != last; it++)
    {
        std::cout << *it << (it != last - 1 ? " / " : "");
    }
    std::cout << "\n";




    // 야콥스탈 수열 인덱스로 pair 정렬, 이후엔 
    // sorted pair empty? 야콥스탈 수열 이용하여 정렬하면서 채우기
    // not empty? 남긴 pair 삽입 

    






    // binary insertion jascobtal



    // while (first < last)
    // {

    // }

    // 102 
    // 3 54  


}

int main()
{
    vec v;
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
    // v.push_back(11);
    // v.push_back(25);
    // v.push_back(45);
    // v.push_back(78);
    // v.push_back(65);
    // v.push_back(1023);
    // v.push_back(329);
    // v.push_back(48);
    // v.push_back(52);
    // v.push_back(60);
    // v.push_back(109);
    // v.push_back(278);
    for (vecIter it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << (it != v.end() - 1 ? " / " : "");
    }
    std::cout << "\n\n";


    int struggler = -1;
    if (v.size() % 2) {
        struggler = v.back();
    }

    
    sort(v, v.begin(), (v.size() % 2 ? v.end() - 1 : v.end()), 2);

   
    std::cout << "\n";
    std::cout << "after" << std::endl;
    for (vecIter it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << (it != v.end() - 1 ? " / " : "");
    }
    std::cout << "\n";

    std::cout << "jacobstal" << std::endl;
    for (vecIter it = jacob.begin(); it != jacob.end(); it++)
    {
        std::cout << *it << (it != jacob.end() - 1 ? " / " : "");
    }
    std::cout << "\n";
}
