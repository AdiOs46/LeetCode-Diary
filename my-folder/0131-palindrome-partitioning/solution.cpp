class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    void helper(int index, string s, vector<string>& curr, vector<vector<string>>& ans) {
        if (index == s.length()) {
            ans.push_back(curr);
            return;
        }

        string curr_string = "";
        for (int i = index; i < s.length(); ++i) {
            curr_string += s[i];
            if (isPalindrome(curr_string)) {
                curr.push_back(curr_string);
                helper(i + 1, s, curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(const string& s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0, s, curr, ans);
        return ans;
    }

};
