class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0, right = sqrt(c);
        while(left <=  right) {
            if(pow(left, 2) + pow(right, 2) < c)
                left++;
            else if(pow(left, 2) + pow(right, 2) > c)
                right--;
            else return true;
        }
        return false;
    }
};
