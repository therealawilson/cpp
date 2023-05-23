#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size()-1; i++)
        {
            for (int j = i+1; j<nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(j);
                    ans.push_back(i);
                    
                    return ans;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution S1;
    std::vector<int> n = {1, 2, 3, 4};
    int t = 5;
    vector<int> ans = S1.twoSum(n,t);
    std::cout << "answer is " << ans[0] << ans[1];
    
    return 0;
}