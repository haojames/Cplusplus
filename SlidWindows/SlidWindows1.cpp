#include "stdio.h"
#include "iostream"
#include "vector"
#include "cmath"
using namespace std;
double findMaxAverage(vector<int>& nums, int k)
{
    double res;
    int counter_SumWindow = 0;
    /*
    Check index < k
    */
    for(int left = 0;left < k;left++)
    {
        counter_SumWindow += nums[left];
    }
    double MaxAverage = double(counter_SumWindow)/k; //Get MaxAverage index < k

    for(int right = k;right < nums.size();right++)
    {
        //cout << right << endl;
        counter_SumWindow += nums[right];
        //cout << "Gia tri: "<< nums[right - k] << endl;
        counter_SumWindow -= nums[right - k];
        MaxAverage =max(MaxAverage,(double)(counter_SumWindow)/k);
    }
    /*
    right = k = 4
    n.size() = 5
    true condition => counter_SumWindow(2) + nums[4](50) = 52
                    counter_SumWindow - nums[0](1) = 52 - 1 = 51 
                    MaxAverage_old = 0.5
                Get  => MaxAverage_new = 51/4 = 12.75

    right = k = 5
    n = 5
    true condition => counter_SumWindow(51) + nums[5](3) = 54
                    counter_SumWindow - nums[1](12) = 54 - 12 = 42
                Get =>    MaxAverage_old = 12.75
                    MaxAverage_new = 42/4 = 10.5
    */
    return MaxAverage;
}
int main()
{
    vector<int> nums = {5};
    int k = 1;
    cout << findMaxAverage(nums,k) << endl; 
    return 0;
}