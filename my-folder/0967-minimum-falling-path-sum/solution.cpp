class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(i < 0 || j < 0 || j >= matrix.size()) return INT_MAX;
        if(i == 0) return matrix[i][j];
        if(dp[i][j] != -101) return dp[i][j];

        int ch1 = helper(i-1, j, matrix, dp);
        int ch2 = helper(i-1, j-1, matrix, dp);
        int ch3 = helper(i-1, j+1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({ch1, ch2, ch3});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -101));

        for(int i=0; i<n; i++) {
            ans = min(ans, helper(n-1, i, matrix, dp));
        }
        return ans;
    }
};
