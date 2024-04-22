class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(auto num : nums) {
            mp[num]++;
        }

        for(auto ele : mp) {
            if (ele.second > n/2) return ele.first;
        }
        return -1;
    }
};
