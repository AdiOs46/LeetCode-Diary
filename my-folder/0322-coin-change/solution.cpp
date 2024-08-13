class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        for(int i=0; i<=amount; i++) {
            if(i % coins[0] == 0) {
                dp[0][i] = i/coins[0];
            }
            else {
                dp[0][i] = 1e9;
            }
        }

        for(int ind=1; ind<coins.size(); ind++) {
            for(int T=0; T <= amount; T++) {
                int nottake = dp[ind-1][T];
                int take = 1e9;
                if(T >= coins[ind])
                    take = 1 + dp[ind][T-coins[ind]];
                dp[ind][T] = min(take, nottake);
            }
        }
        int ans = dp[coins.size()-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }   
};
