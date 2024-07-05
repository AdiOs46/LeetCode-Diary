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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        return height(root) != -1;
    }

    int height(TreeNode* root){
        if(!root) return 0;

        int countL = height(root->left);
        if (countL == -1) return -1;

        int countR = height(root->right);
        if (countR == -1) return -1;

        if(abs(countL - countR) > 1) return -1;
        return max(countL, countR) + 1;
    }
};
