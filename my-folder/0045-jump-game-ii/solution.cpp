class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach=0, count=0, n = nums.size(), currentEnd=0;
        if(n == 1) return 0;
        for(int i=0; i<n; i++) {
            maxReach = max(maxReach, i+nums[i]);
            if(i == currentEnd) {
                currentEnd = maxReach;
                count++;
                if(currentEnd >= n-1) return count;
            }
        }
        return count;
    }
};
