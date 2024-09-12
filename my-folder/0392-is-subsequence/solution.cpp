class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length();

        int curr = 0;
        for(int i=0; i<n; i++) {
            if(s[curr] == t[i]) {
                curr++;
            }
        }

        if(curr >= s.length()) return true;
        return false;
    }
};
