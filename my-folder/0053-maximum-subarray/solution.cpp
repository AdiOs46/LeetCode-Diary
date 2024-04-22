class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

       int sum=0,maxx=INT_MIN;
       for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(sum > maxx) maxx = max(maxx, sum);
            if(sum < 0) sum = 0;
       }
       return maxx;
    }
};
