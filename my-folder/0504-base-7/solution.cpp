class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";

        int base = 7;
        string ans = "";
        int sign = 0;
        
        if(num < 0) {
            num = -(num);
            sign = 1;
        }

        while (num > 0) {
            ans += to_string(num%base);
            num /= base;
        }

        if(sign == 1) ans += "-";

        int left=0, right= ans.length()-1;
        while(left <= right) {
            swap(ans[left++], ans[right--]);
        }

        return ans;
    }
};
