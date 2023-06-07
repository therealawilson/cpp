//Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.
//
//Implement the Solution class:
//
//Solution(int[] nums) Initializes the object with the integer array nums.
//int[] reset() Resets the array to its original configuration and returns it.
//int[] shuffle() Returns a random shuffling of the array.

#include<string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        copy = nums;
    }
    
    vector<int> reset() {
        return copy;
    }
    
    vector<int> shuffle() {
        for (int i = 0; i < copy.size(); i++){
            int j = rand()%copy.size();
            swap(copy[i], copy[j]);
        }
        return copy;
    }

private:
    vector<int> copy;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main()
{
    vector<int> nums({1,2,3,4});
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();

    for (auto i : param_1){
        cout << i << " ";
    }
    for (auto i : param_2){
        cout << i << " ";
    }

    return 0;
}