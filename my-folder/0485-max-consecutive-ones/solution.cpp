class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=INT_MIN, count=0;
        for(int i=0; i<nums.size(); i++) {
            count += nums[i];
            if(count > max) max = count;
            if (nums[i] == 0) count = 0;
        }
        return max;
    }
};
