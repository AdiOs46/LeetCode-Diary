class Solution {
public:
    int helper(int index, int curr_sum, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(index >= nums.size()) return 0;
        if(curr_sum > target) return 0;
        if(curr_sum == target) return 1;
        if(dp[index][curr_sum] != -1) return dp[index][curr_sum];

        int pick = helper(index+1, curr_sum + nums[index], target, nums, dp);
        int notpick = helper(index+1, curr_sum, target, nums, dp);

        return dp[index][curr_sum] = pick || notpick;

    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(auto it : nums) target += it;
        if(target % 2 != 0) return false;
        target /= 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        return helper(0, 0, target, nums, dp);
    }
};
