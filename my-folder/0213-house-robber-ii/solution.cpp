class Solution {
public:
     int helper(vector<int>& nums) {
        int n = nums.size();
        
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

    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> nums1;
        for(int i=0; i<n-1; i++) nums1.push_back(nums[i]);
        int t1 = helper(nums1);

        nums1.clear();
        for(int i=1; i<n; i++) nums1.push_back(nums[i]);
        int t2 = helper(nums1);

        return max(t1, t2);
    }
};
