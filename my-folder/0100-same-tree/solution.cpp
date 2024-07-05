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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        inorder(p,q, ans);
        return ans;
    }

    void inorder(TreeNode* p, TreeNode* q, bool& ans) {
        if(p && !q || q && !p ) {
            ans = false;
            return;
        };
        if(!p && !q) return;

        inorder(p->left, q->left, ans);
        if(p->val != q->val) {
            ans = false;
            return;
        }
        inorder(p->right, q->right, ans);
    }
};
