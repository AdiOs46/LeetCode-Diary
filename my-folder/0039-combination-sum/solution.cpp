class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(candidates,0,0, temp, target, ans);
        return ans;
    }

    void func(vector<int>& candidates, int index, int sum, vector<int>& temp, int target, vector<vector<int> >& ans) {
        if(sum > target) return;
        if(index == candidates.size()) {
            if(sum == target) ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[index]);
        sum += candidates[index];
        func(candidates, index, sum, temp, target, ans);
        temp.pop_back();
        sum -= candidates[index];
        func(candidates, index+1, sum, temp, target, ans);
        //choose picked number unlimited times until criteria is met. If not picking, move to next index and try again.
    }
};
