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
    void preorder(TreeNode* root, TreeNode*& curr) {
        if(!root) return;

        TreeNode* temp = new TreeNode(root->val);
        curr->right = temp;
        curr = curr->right;

        preorder(root->left, curr);
        preorder(root->right, curr);
    }
    void flatten(TreeNode* root) {
        if (!root) return;

        TreeNode* newRoot = new TreeNode();
        TreeNode* curr = newRoot;
        preorder(root, curr);

        root->left = nullptr;
        root->right = newRoot->right->right;
    }
};
