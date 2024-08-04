class Solution {
public:
    int helper(int index, vector<int>& nums, vector<int>& dp) {
        if (index >= nums.size()) return 0;

        if(dp[index] != -1) return dp[index];

        int includeCurrent = nums[index] + helper(index + 2, nums, dp);
        int excludeCurrent = helper(index + 1, nums, dp);

        return dp[index] = max(includeCurrent, excludeCurrent);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};
