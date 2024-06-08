class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0, right = 0, maxCount = 0;

        while (right < s.length()) {
            mp[s[right]]++;
            while (mp[s[right]] > 1) {
                mp[s[left]]--;
                left++;
            }
            maxCount = max(maxCount, right - left + 1);
            right++;
        }
        return maxCount;
    }
};

