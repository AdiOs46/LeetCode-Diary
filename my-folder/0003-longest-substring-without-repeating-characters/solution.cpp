class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int low=0, high=0;
        unordered_map<char, int> mp;
        int count = 0;

        for(high = 0; high<n; high++) {
            if(mp.find(s[high]) != mp.end() && mp[s[high]] >= low) 
                low = mp[s[high]]+1;
            
            mp[s[high]] = high;
            count = max(count, high-low+1);
        }

        return count;
    }
};
