class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0, ans=0, count=0;
        unordered_map<char, int> mp;
        for(int right=0; right<s.length(); right++) {
            mp[s[right]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1) {
                count += s.length() - right;
                mp[s[left++]]--;
            }
        }
        return count;
    }
};
