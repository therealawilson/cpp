//Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
//Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
//Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
//Return k.
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
class Solution{
public:
    int removeDuplicates(vector<int> &nums)
    {
        for (vector<int>::iterator it = nums.begin(); it != nums.end()-1;)
        {
            if (*it == *(it+1))
            {
                nums.erase(it);
            }
            else
            {
                it++;
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution s1;
    vector<int> nums = {1,1,2,3,4,4,5};
    cout << s1.removeDuplicates(nums);

    return 0;
}