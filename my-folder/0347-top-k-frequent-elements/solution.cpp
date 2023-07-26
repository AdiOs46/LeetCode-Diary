class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> ans;
        for(auto i=mp.rbegin(); i!=mp.rend();  i++) {
            ans.push_back(make_pair((*i).second, (*i).first));
        }
        sort(ans.begin(), ans.end(), greater<>());

        vector<int> fa;
        for(int i=0; i<k; i++) {
            fa.push_back(ans[i].second);
        }
        return fa;
    }
};
