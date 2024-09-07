class Solution {
public:
    int rev(long long x) {
        long long ans = 0;
        while(x > 0) {
            long long dig = x%10;
            ans = (ans * 10) + dig;
            x /= 10;
        }   
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;

        map<long long, long long> mp;
        for(auto it : nums) {
            mp[it - rev(it)]++;
        }

        for(auto it : mp){
            long long v = it.second;
            if (v > 1) {
                count += v * (v - 1);
            }
        }

        return (count >> 1) % (int)(1e9 + 7);
    }
};
