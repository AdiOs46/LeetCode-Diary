class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxFreq = 0, ans = -1, n = s.size();
        unordered_map<char,int>mp;
        for(int right=0; right<n; right++)
        {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);
            if((right-left+1) - maxFreq > k){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, (right-left+1));
        }
        return ans;
    }
};
