class Solution {
public:
    int helper(int i, int j, int n,  vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == n) return triangle[i][j];
        if(i > n || j > n) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];

        int choice1 = helper(i+1, j, n, triangle, dp);
        int choice2 = helper(i+1, j+1, n, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(choice1, choice2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1 && triangle[0].size() == 1) return triangle[n-1][n-1];
        vector<vector<int>> dp(n);
        for(int i=0; i<n; i++) dp[i] = vector<int>(triangle[i].size(), -1);
        return helper(0, 0, n-1, triangle, dp);
    }
};
