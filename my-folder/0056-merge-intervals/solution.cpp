class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size() == 1) return intervals;

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        auto curr_interval= intervals[0];
        
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= curr_interval[1])
                curr_interval[1] = max(curr_interval[1], intervals[i][1]);
            else {
                ans.push_back(curr_interval);
                curr_interval = intervals[i];
            }
        }

        ans.push_back(curr_interval);
        return ans;
    }
};
