class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return dfs(root, targetSum, sum);
    }

    bool dfs(TreeNode* root, int targetSum, int sum) {
        if(!root) {
            return false;
        }
        
        sum += root->val;

        if(sum == targetSum && !root->left && !root->right) return true;

        bool leftResult = dfs(root->left, targetSum, sum);
        bool rightResult = dfs(root->right, targetSum, sum);
        
        return leftResult || rightResult;
    }
};
