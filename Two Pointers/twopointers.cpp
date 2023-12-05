#include "stdio.h"
#include "vector"
#include "cmath"
#include <iostream>

using namespace std;
/*
--------------------------------------
Flow Chart
--------------------------------------
Time complexity
    Two Pointer Approach
    Compare left square and right square
    Browse the array with each element[nums = sortedArray.size()]
    -> O(N)
Space complexity
    Use vector ans to storage square array. -> O(N)
*/

// std::vector<int> squareArray(const std::vector<int>& sortedArray)
// {
//     int left = 0;
//     int right = sortedArray.size() - 1;
//     vector<int> squaredArray(sortedArray.size());
//     for(int i = sortedArray.size() - 1; i>=0;i--)
//     {
//         int leftSquare = sortedArray[left]*sortedArray[left];
//         int rightSquare = sortedArray[right]*sortedArray[right];
//         if(abs(leftSquare) > rightSquare)
//         {
//             squaredArray[i] = leftSquare;
//             left++;
//         }
//         else
//         {
//             squaredArray[i] = rightSquare;
//             right--;
//         }
//     }
//     // Squaring
//     return squaredArray;
// }
std::vector<int> squareArray(const std::vector<int>& sortedArray)
{
    int nums = sortedArray.size();
    int left =0;
    int right = nums - 1;
    int locationResult = nums - 1;
    vector<int> res(nums);
    while(left <= right)
    {
        if(abs(sortedArray[left]) > abs(sortedArray[right]))
        {
            res[locationResult--] = sortedArray[left]*sortedArray[left];
            left++;
        }
        else
        {
            res[locationResult--] = sortedArray[right]*sortedArray[right];
            right--;
        }
    }
    return res;
}
int main()
{
    std::vector<int> sortedArray = {-7, -3, 2, 3, 11};
    std::vector<int> squaredArray = squareArray(sortedArray);
    //Sort
    for (const auto& num : squaredArray)
    {
        std::cout << num << " ";
    }
    return 0;
}
