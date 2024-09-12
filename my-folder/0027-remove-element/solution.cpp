class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int end = nums.size()-1;
        for(int i=0; i<=end; i++) {
            if(nums[i] == val) {
                while(i < end && nums[end] == val) {
                    nums[end] = -1;
                    end--;
                }
                swap(nums[i], nums[end--]);
            }
        }

        return end+1;
    }
};
