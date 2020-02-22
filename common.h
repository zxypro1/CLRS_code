#pragma once
#include <vector>
#include <iostream>

template <typename T>
void Print(const std::vector<T> &v)
{
    for (T i : v)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}
