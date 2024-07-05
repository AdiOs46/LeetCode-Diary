/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return NULL;
        int maxDepth = 1;
        findDepth(root, 1, maxDepth);
        return maxDepth;
    }

    void findDepth(TreeNode* root, int currDepth, int& maxDepth) {
        if(!root) return;

        maxDepth = max(currDepth, maxDepth);
        findDepth(root->left, currDepth+1, maxDepth);
        findDepth(root->right, currDepth+1, maxDepth);
    }
};
