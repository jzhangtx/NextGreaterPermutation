// NextGreaterPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

//void TraceVector(const std::vector<int>& v)
//{
//    std::cout << "{";
//    for (auto i = v.cbegin(); i != v.cend(); ++i)
//    {
//        if (i != v.cbegin())
//            std::cout << ", ";
//        std::cout << *i;
//    }
//
//    std::cout << "}" << std::endl;
//}
//
void AddPermutationNoDuplicates(std::vector<std::vector<int>>& arrays, const std::vector<int>& arr)
{
    for (auto& ar : arrays)
    {
        bool arrayFound = true;
        for (size_t i = 0; i < arr.size(); ++i)
        {
            if (ar[i] != arr[i])
            {
                arrayFound = false;
                break;
            }
        }
        if (arrayFound)
            return;
    }

    arrays.push_back(arr);
}

//int tried = 0;
void Permutations1(std::vector<std::vector<int>>& permutations, std::vector<int>& arr, int index)
{
    //TraceVector(arr);
    //tried++;
    AddPermutationNoDuplicates(permutations, arr);

    for (size_t i = index; i < arr.size() - 1; ++i)
    {
        for (size_t j = i + 1; j < arr.size(); ++j)
        {
            std::swap(arr[i], arr[j]);
            Permutations1(permutations, arr, index + 1);
            std::swap(arr[i], arr[j]);
        }
    }
}

void Permutations(std::vector<std::vector<int>>& permutations, std::vector<int>& arr, int index)
{
    //tried++;
    if (index == arr.size() - 1)
    {
        AddPermutationNoDuplicates(permutations, arr);
        return;
    }

    for (size_t i = index; i < arr.size(); ++i)
    {
        std::swap(arr[i], arr[index]);
        Permutations(permutations, arr, index+1);
        std::swap(arr[i], arr[index]);
    }
}

void NextGreaterPermutation(std::vector<int>& arr)
{
    std::vector<std::vector<int>> permutations;
    
    Permutations(permutations, arr, 0);
    //std::cout << "Tried " << tried << " times" << std::endl;
    std::sort(permutations.begin(), permutations.end());

    for (auto i = permutations.cbegin(); i != permutations.cend(); ++i)
    {
        if (arr == *i)
        {
           arr.clear();
           if (i + 1 == permutations.cend())
           {
               std::vector<int> v(*permutations.cbegin());
               arr.assign(v.cbegin(), v.cend());
           }
           else
           {
               std::vector<int> v(*(i + 1));
               arr.assign(v.cbegin(), v.cend());
           }
           return;
        }
    }
}

int main()
{
    while (true)
    {
        //tried = 0;
        int count = 0;
        std::cout << "Number of elements in the array: ";
        std::cin >> count;
        if (count == 0)
            break;

        std::vector<int> vec(count);
        std::cout << "The number array: ";
        for (int i = 0; i < count; ++i)
            std::cin >> vec[i];

        std::cout << "Next Greater Permutation: " << std::endl;
        NextGreaterPermutation(vec);
        for (size_t i = 0; i < vec.size(); ++i)
        {
            if (i != 0)
                std::cout << ", ";
            std::cout << vec[i];
        }

        std::cout << std::endl;
    }
}
