// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int> nums)
    {
        int count = 1;
        int target = nums.size()/2;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i] == nums[i+1])
            {
                count++;
            }
            else
            count = 1;

            if (count >= target)
            return nums[i];
        }
        return 0;
    }
};

int main()
{
    vector<int> nums = {1,2,5,2,3,2};
    Solution s1;
    cout<< s1.majorityElement(nums);
    return 0;
}