class Solution {
public:
    void generate(int open, int close, string str, vector<string>& ans) {
        if(open == 0 && close == 0) {
            ans.push_back(str);
            return;
        }

        if(open > 0) {
            generate(open-1, close, str + "(", ans);
        }

        if(close > open) {
            generate(open, close-1, str + ")", ans);
        }

    }
    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        vector<string> ans;
        generate(n, n, "", ans);
        return ans;
    }
};
