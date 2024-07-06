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
    bool isValidBST(TreeNode* root) {
        if(!root) return false;
        TreeNode* prev = nullptr;
        return inorder(root, prev);
    }

    bool inorder(TreeNode* root, TreeNode*& prev) {
        if(!root) return true;

        if(!inorder(root->left, prev)) return false;
        if(prev && prev->val >= root->val) return false;
        prev = root;
        if(!inorder(root->right, prev)) return false;
        return true;
    }
};
