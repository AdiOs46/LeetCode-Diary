class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> mp;
        string str;
        vector<string> ans;
        string temp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        combos(digits, 0, temp, ans, mp);
        return ans;
    }

    void combos(string& digits, int index, string temp, vector<string>& ans, unordered_map<char, string>& mp) {
        if(temp.length() > digits.length()) return;
        if(temp.length() == digits.length()) {
            ans.push_back(temp);
            return;
        }

        char digit = digits[index];
        string str = mp[digit];

        for(char letter : str) {
            temp.push_back(letter);
            combos(digits, index+1, temp, ans, mp);
            temp.pop_back();
        }
    }
};
