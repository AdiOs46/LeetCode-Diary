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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiam = 0;
        diameter(root, maxDiam);
        return maxDiam;
    }

    int diameter(TreeNode* root, int& maxDiam) {
        if(!root) return 0;

        int left = diameter(root->left, maxDiam);
        int right = diameter(root->right, maxDiam);
        maxDiam = max(maxDiam, left+right);
        return max(left, right) + 1;
    }
};
