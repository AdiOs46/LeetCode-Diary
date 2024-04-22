class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxx = 0;
        int n = prices.size();
        int minn = INT_MAX;

        for (int i = 0; i < n; i++) {
            minn = min(minn, prices[i]);
            maxx = max(maxx, prices[i] - minn);
        }
        return maxx;
    }
};
