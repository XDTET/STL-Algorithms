
#include <iostream>
#include <algorithm>
#include <vector>
#include<memory>
#include "Dog.h"

int main()
{
    int collection[4]{ 1,2,3,4 };
    
    std::vector<int> wektor1{ 1,2,3,4 };
    std::vector<int> wektor2(wektor1.size());

    if (std::all_of(std::begin(collection), std::end(collection), [](int i) {return i % 2 == 0; }))
    {
        std::cout << "All elements of collection are even " << std::endl;
    }
    else if(std::any_of(std::begin(collection), std::end(collection), [](int i) {return i % 2 == 0; }))
    {
        std::cout << "At least one element of collection are even " << std::endl;

    }
    else if (std::none_of(std::begin(collection), std::end(collection), [](int n) {return n % 2 == 0; }))
    {
        std::cout << "None of elements in collection are even " << std::endl;

    }
    int two_count = std::count_if(std::begin(collection), std::end(collection), [](int n) {return n == 2; });
    std::cout << two_count << std::endl;

    auto copy_four = std::copy_if(wektor1.begin(), wektor1.end(), wektor2.begin(), [](int n) {return n == 4; });

    wektor2.resize(std::distance(wektor2.begin(), copy_four));

    auto loops = std::for_each(std::begin(wektor2), std::end(wektor2), [](int n) {std::cout << n << std::endl; });
}
