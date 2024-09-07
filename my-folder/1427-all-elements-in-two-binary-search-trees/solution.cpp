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

    void traversal(TreeNode* root, vector<int>& tree) {
        if (root == nullptr) return;

        traversal(root->left, tree);
        tree.push_back(root->val);
        traversal(root->right, tree);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> tree1, tree2;
        vector<int> ans;

        traversal(root1, tree1);
        traversal(root2, tree2);

        if(!tree1.size()) return tree2;
        if(!tree2.size()) return tree1;

        int s1 = tree1.size(), s2 = tree2.size();
        int p1=0, p2=0;

        while(p1 < s1 && p2 < s2) {
            if(tree1[p1] < tree2[p2])
                ans.push_back(tree1[p1++]);
            else if(tree1[p1] > tree2[p2])
                ans.push_back(tree2[p2++]);
            else {
                ans.push_back(tree1[p1]);
                ans.push_back(tree2[p2]);
                p1++;
                p2++;
            }
        }
        
        while(p1 < s1) ans.push_back(tree1[p1++]);
        while(p2 < s2) ans.push_back(tree2[p2++]);

        return ans;

    }
};
