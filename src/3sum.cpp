//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such
// that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//
//Notice that the solution set must not contain duplicate triplets.

#include<string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include<vector>
#include<set>

using namespace std;

class Triplet{
public:

    vector<vector<int>> isSumBrute(vector<int> nums)
    {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());  //not needed for Brute Force method
        set<vector<int>> s;

        for (int i = 0; i < temp.size()-2; i++){
            for (int j = i+1; j < temp.size()-1; j++){
                for (int k = i+2; k < temp.size(); k++){
                    if (temp[i]+temp[j]+temp[k] == 0){
                        vector<int> trip{temp[i], temp[j], temp[k]};
                        s.insert(trip);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto& x : s)
        {
            ans.push_back(x);
        }
        return ans;
    }


    vector<vector<int>> isSumOpt(vector<int> nums)
    {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());  //not needed for Brute Force method
        set<vector<int>> s;

        for (int i = 0; i < temp.size()-2; i++){
           int j = i+1;
           int k = temp.size()-1;
           while (j < k)
           {
                if (temp[i]+temp[j]+temp[k] == 0){
                    vector<int> trip{temp[i], temp[j], temp[k]};
                    s.insert(trip);
                    j++;
                    k--;
                }
                else if (temp[i]+temp[j]+temp[k] < 0){
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        
        vector<vector<int>> ans;
        for (auto x : s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};

int main()
{
    Triplet t1;
    vector<int> nums{1, -1, 2, 3, -3, 4};
    vector<vector<int>> ans1 = t1.isSumBrute(nums);
    cout <<"Brute force method:" << endl;
    for (auto x : ans1){
        cout << x[0] <<' ' << x[1] << ' ' << x[2] << endl;
    }
   

    vector<vector<int>> ans2 = t1.isSumOpt(nums);
    cout <<"Optimized method:" << endl;
    for (auto x : ans2){
        cout << x[0] <<' ' << x[1] << ' ' << x[2] << endl;
    }

 return 0;
}