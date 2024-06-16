class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums) mp[num]++;

        priority_queue<pair<int, int>> pq;
        for(auto i=mp.begin(); i!=mp.end();  i++)
            pq.push(make_pair(i->second, i->first));
        
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back((pq.top()).second);
            pq.pop();
        }
        return ans;
    }
};
