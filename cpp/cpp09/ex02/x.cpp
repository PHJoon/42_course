#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

typedef std::vector<int>::iterator vecIter;

void    sort(std::vector<int> vec, vecIter first, vecIter last)
{
    std::ptrdiff_t size = std::distance(first, last);
    if (size < 2) return;
    
    for (vecIter it = first; it != last; it++) {
        std::cout << *it << " / ";
    }

    std::cout << std::endl;

    bool straggler = false;
    if (size % 2) {
        straggler = true;
    }

    for (vecIter it = first; it != (straggler ? last - 1 : last); it += 2) {
        if (*it < *(it + 1)) {
            int tmp = *it;
            *it = *(it + 1);
            *(it + 1) = tmp;
        }
    }

    // largest element swap

    std::cout << "end\n";
    sort(vec, first, first + size / 2);
    sort(vec, first + size / 2, last);

    // 큰 값 main, 작은 값 pend


    for (vecIter it = first; it != last; it++) {
        std::cout << *it << " / ";
    }
    std::cout << std::endl;
    
}

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(12);
    vec.push_back(5);
    vec.push_back(34);
    vec.push_back(124);
    vec.push_back(6);
    vec.push_back(9);
    vec.push_back(55);
    vec.push_back(97);

    sort(vec, vec.begin(), vec.end());
}
