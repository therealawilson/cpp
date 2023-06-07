#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        deque<pair<TreeNode*, int>> q;
        q.push_back({root, 1});
        int prev_level = 1;
        double sum = 0;
        double count = 1;
        vector<double> ans = 0;

        while (!q.empty())
        {
            TreeNode* curr = q.front().first;
            int level = q.front().second;
            q.pop_front();

            if (prev_level == level)
            {
                sum+=curr->val;
                count++;
            }
            else
            {
                prev_level = level;

                ans.push_back(sum/count);
                sum = curr->val;
                count = 1;

            }
            if (curr->left)
            {
                q.push_back({curr->left, level+1});
            }
            if (curr->right)
            {
                q.push_back({curr->right, level+1});
            }
        }
        ans.push_back(sum/count);
    }
};