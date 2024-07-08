class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder, INT_MAX, i); 
    }

    TreeNode* build(vector<int>& preorder, int upperbound, int& i) {
        if(i == preorder.size() || preorder[i] > upperbound) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, root->val, i);
        root->right = build(preorder, upperbound, i);
        return root;
    }
};
