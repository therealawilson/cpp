// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i =0; i < n; i++)
        {
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main()
{
    Solution s1;
    vector<int> n1 = {1,3,5,0,0,0};
    vector<int> n2 = {2,4,6};
    int size1 = n1.size()-3;
    int size2 = n2.size();

    s1.merge(n1,size1,n2,size2);

    for (int i : n1)
    {
        cout << i << ' ';
    }
    return 0;   

}