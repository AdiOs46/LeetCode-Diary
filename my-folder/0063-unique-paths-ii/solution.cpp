class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(m < 0 || n < 0) return 0;
        if(obstacleGrid[m][n] == 1) {
            dp[m][n] = 0;
            return 0;
        }

        if(m == 0 && n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n];

        int up = helper(m-1, n, obstacleGrid, dp);
        int left = helper(m, n-1, obstacleGrid, dp);

        return dp[m][n] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0; 
        if(m == 1 && n == 1) return 1;
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, obstacleGrid, dp);
    }
};
