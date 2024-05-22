class Solution {
    public:
    string largestOddNumber(string num) {
        std::ios_base::sync_with_stdio(0);
        cin.tie(0);
        int numSize = num.length()-1;
        for(int i=numSize; i>=0; i--) {
            if(int(num[i]) % 2 != 0) 
                return num.substr(0, i+1);
        }
        return "";
    }
};
