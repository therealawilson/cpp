#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

class Btree {
public:


    int maxDepth(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        int ans = max(maxLeft,maxRight) + 1;
        return ans;
    }
};

int main()
{
    Btree t1;
    TreeNode l2 (1);
    TreeNode r2 (1);
    TreeNode l1 (4,&l2,&r2);
    TreeNode r1 (3);
    TreeNode root(5,&l1,&r1);

    cout << t1.maxDepth(&root);

    return 0;
}