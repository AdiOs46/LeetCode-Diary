class Solution {
public:
    vector<vector<int>> result;
    
    void func(vector<int> &curr, int target, int sum, vector<int> &candidates, int curInd, int n){
        if(sum > target) return;
        if(target == sum){
            result.push_back(curr);
            return;
        }
        
        for(int i = curInd; i < n; i++){
            if(i != curInd && candidates[i]==candidates[i-1])
                continue;

            curr.push_back(candidates[i]);
            sum += candidates[i];
            func(curr, target, sum, candidates, i+1, n);
            curr.pop_back();
            sum -= candidates[i];
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        func(curr, target, 0, candidates, 0, n);
        return result;
    }
};
