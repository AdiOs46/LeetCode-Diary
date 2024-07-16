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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        return bfs(root);
    }
    int bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sum = 0;
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                sum += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();
            }
            if(q.empty()) return sum;
        }
        return 0;
    }
};
