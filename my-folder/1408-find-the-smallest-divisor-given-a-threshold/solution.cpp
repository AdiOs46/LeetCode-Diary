class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 1e9;

        while(low <= high) {
            int divisor = (low + high)/2;
            int sum = 0;

            for(auto num : nums) {
                sum += ceil((double)num/(double)divisor);
                if(sum > threshold) break;
            }

            if(sum > threshold)
                low = divisor + 1;
            else
                high = divisor - 1;
        }

        return low;
    }
};
