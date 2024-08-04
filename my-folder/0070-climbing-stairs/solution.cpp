class Solution {
public:
    int climbTop(int n, vector<int>& dp) {
        if(n <= 2) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = climbTop(n-1, dp) + climbTop(n-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return climbTop(n, dp);
    }
};
