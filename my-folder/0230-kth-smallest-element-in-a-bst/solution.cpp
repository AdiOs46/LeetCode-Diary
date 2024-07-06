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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int ans, count=0;
        findSmallest(root, k, ans, count);
        return ans;
    }

    void findSmallest(TreeNode* root, int k, int& ans, int& count) {
        if(!root) return;

        findSmallest(root->left, k, ans, count);
        count++;
        if(k == count) {
            ans = root->val;
            return;
        }
        findSmallest(root->right, k, ans, count);
    }


};
