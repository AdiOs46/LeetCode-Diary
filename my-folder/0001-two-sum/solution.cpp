class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); i++) {
            int check = target - nums[i];
            if(m.count(check) && m[check] != i)
                return {i, m[check]};
        }

        return {};
        
    }
};
