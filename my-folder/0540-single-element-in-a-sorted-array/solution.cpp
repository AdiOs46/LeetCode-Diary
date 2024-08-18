class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low < high) {
            int mid = (low + high) /2;
            
            if((mid % 2 == 0 && nums[mid+1] == nums[mid]) || (mid % 2 == 1 && nums[mid-1] == nums[mid]))
                low = mid + 1;
            else 
                high = mid;
        }

        return nums[low];
    }
};
