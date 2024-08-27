class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int k = floor(n/3);
        unordered_map<int, int> mp;
        for(auto it : nums) mp[it]++;

        for(auto it : mp) {
            if(it.second > k) ans.push_back(it.first);
        }

        return ans;
    }
};
