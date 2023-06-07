//Given an array of intervals where intervals[i] = [starti, endi], 
//merge all overlapping intervals, and return an array of the non-overlapping
//intervals that cover all the intervals in the input.

#include<string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include<vector>

using namespace std;

class Intervals{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for (auto interval : intervals)
        {
            if (merged.empty() || interval[0] > merged.back()[1])
            {
                merged.push_back(interval);
            }
            else{
                merged.back()[1] = max(interval[1], merged.back()[1]);
            }
        }
        return merged;
    }
};

int main()
{
    Intervals i1;
    vector<vector<int>> intervals{{1,3}, {2,4}, {6,7}};
    auto ans = i1.merge(intervals);
    for (auto i : ans)
    {
        cout << i[0] << " " << i[1] << endl;;
    }
    return 0;

}