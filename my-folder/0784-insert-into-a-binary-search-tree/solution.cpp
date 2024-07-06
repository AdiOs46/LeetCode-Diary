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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* toInsert = new TreeNode(val);
        TreeNode* prev = nullptr;
        if (root == nullptr) return toInsert;
        
        insert(root, prev, toInsert);
        return root;
    }

    void insert(TreeNode* curr,TreeNode*& prev, TreeNode*& toInsert) {

        if(curr == NULL) {
            if(toInsert->val > prev->val) 
                prev->right = toInsert;
            else 
                prev->left = toInsert;
            return;
        }
        
        prev = curr;
        if(toInsert->val > curr->val)
            insert(curr->right, prev, toInsert); 
        else
            insert(curr->left, prev, toInsert); 
    }

};
