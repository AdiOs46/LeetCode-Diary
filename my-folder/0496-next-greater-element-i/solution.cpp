class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums2.size();

        for(int i = n-1; i >=0; i--) {
            while(!st.empty() && nums2[i] > st.top())
                st.pop();

            if(!st.empty() && nums2[i] < st.top())
                mp[nums2[i]] = st.top();
                
            st.push(nums2[i]);
        }

        for(auto it : nums1) {
            if(mp.find(it) != mp.end()) ans.push_back(mp[it]);
            else ans.push_back(-1);
        }

        return ans;
    }
};
