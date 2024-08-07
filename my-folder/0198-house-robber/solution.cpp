class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        int prev = nums[0];
        int prev2 = 0;

        for(int i=1; i<n; i++) {
            int take = nums[i];
            if(i > 1) take += prev2;
            
            int nontake = prev;
            int curri = max(take, nontake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};
