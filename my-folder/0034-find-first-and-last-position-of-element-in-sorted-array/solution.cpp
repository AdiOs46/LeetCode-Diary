class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int ansF=-1, ansL=-1;
    
        while(low<=high) {
            int mid = low + (high-low)/2;

            if(nums[mid] == target) {
                ansL = mid;
                low = mid+1;
            }
            else if(nums[mid] < target) 
                low = mid+1;
            else 
                high = mid-1;
        }

        low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ansF = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return {ansF, ansL};
    }
};
