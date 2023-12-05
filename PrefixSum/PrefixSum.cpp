#include "cmath"
#include "vector"
#include "iostream"
using namespace std;


/*
time complexity => O(n)
space complexity => O(1)
*/
int minStartValue(vector<int>& nums)
{
    int startValue = 1, tempValue = 1;
    for(int i = 0;i<nums.size();i++)
    {
        tempValue += nums[i];
        cout << "Step: \t" << i << " Value: \t "<< tempValue <<endl;
        cout << tempValue << endl;
        if(tempValue < 1)
        {
            startValue += (1 - tempValue); 
            tempValue = 1;
            cout << startValue << endl;
        }
        cout << "===========================" << endl;
    }
     return startValue;
}

int main()
{
    vector<int> nums = {-3,2,-3,4,2};
    cout << minStartValue(nums);
    return 0;
}