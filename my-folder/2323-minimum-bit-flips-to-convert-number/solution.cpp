class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal, count=0;

        while (temp) {
            temp = temp&(temp-1);
            count++;
        }
        return count;
    }
};
