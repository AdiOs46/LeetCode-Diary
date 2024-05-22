class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int openP=0, closeP=0, start=0;

        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(c == '(') openP++;
            else if (c == ')') closeP++;

            if(openP == closeP) {
                result += s.substr(start+1, i-start-1);
                start = i+1;
            }
        }
            return result;
    }
};
