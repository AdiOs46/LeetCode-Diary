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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        ans.push_back({root->val});

        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> temp;

            for(int i=0; i<levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left) {
                    temp.push_back(curr->left->val);
                    q.push(curr->left);
                }

                if(curr->right) {
                    temp.push_back(curr->right->val);
                    q.push(curr->right);
                }
            }

            if(temp.size() != 0) ans.push_back(temp);
        }

        return ans;
    }
};
