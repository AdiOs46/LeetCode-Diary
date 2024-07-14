class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0, right=1;
        for(right=1; right<nums.size(); right++) {
            if(nums[left] == 0 && nums[right]!=0) swap(nums[left], nums[right]);
            if(nums[left] != 0) left++;
        }
    }
};
