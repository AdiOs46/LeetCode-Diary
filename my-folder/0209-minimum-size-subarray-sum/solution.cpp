class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int n = nums.size();

        int low=0, high=0;
        int curr = 0;
        for(high=0; high<n; high++) {
            curr += nums[high];
            if(curr >= target) {
                while(curr >= target) {
                    minLength = min(minLength, high-low+1);
                    curr -= nums[low];
                    low++;
                }
            }
        }

        if(minLength == INT_MAX) return 0;
        return minLength;
    }
};
