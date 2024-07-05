class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        findSubset(ans, nums, temp, 0);
        return ans;
    }

    void findSubset(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, int index) {
        
        ans.push_back(temp);

        for(int i=index; i<nums.size(); i++){
            temp.push_back(nums[i]);
            findSubset(ans, nums, temp, i+1);
            temp.pop_back();
        }
    }
};
