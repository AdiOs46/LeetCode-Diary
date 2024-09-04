class Solution {
public:
    void helper(int index, int sum, int n, int k, vector<int> combo, vector<vector<int>>& ans) {
        if(sum > n || combo.size() > k) return;

        if(combo.size() == k) {
            if(sum == n)
                ans.push_back(combo);
            return;
        }
        
        for(int i = index; i < 10; i++) {
            combo.push_back(i);
            helper(i+1, i+sum, n, k, combo, ans);
            combo.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> combo;
        helper(1, 0, n, k, combo, ans);
        return ans;
    }
};
