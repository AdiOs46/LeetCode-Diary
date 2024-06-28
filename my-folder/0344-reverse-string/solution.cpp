class Solution {
public:
    void reverseString(vector<char>& s) {
        move(s, 0, s.size());
    }

    void move(vector<char>& s, int i, int n) {
        if(i >= n/2) return;
        swap(s[i], s[n-i-1]);
        move(s, i+1, n);
    }
};
