class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        if (size <= 1) return size;
        int count = 1;

        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[i - 1]) { 
                nums[count] = nums[i];
                count++;
            }
        }

        for (int i = count; i < size; i++) {
            nums[i] = -1;
        }
        return count;
    }
};
