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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> stack1;
        stack1.push(root);
        while(!stack1.empty()) {
            TreeNode* curr = stack1.top();
            stack1.pop();
            result.push_back(curr->val);
            if(curr->left) stack1.push(curr->left);
            if(curr->right) stack1.push(curr->right);
        }
        reverse(result.begin(), result.end());
        return result;   
    }
};
