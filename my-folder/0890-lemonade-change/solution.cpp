class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change=0;
        unordered_map<int, int> mp;
        for(int i=0; i<bills.size(); i++) {
            mp[bills[i]]++;
            if(bills[i] == 10){
                mp[5]--;
                if(mp[5] < 0) return false;
            }
            if(bills[i] == 20) {
                if(mp[10] == 0) {
                    mp[5] -= 3;
                    if(mp[5] < 0) return false;
                } else {
                    mp[10]--;
                    mp[5]--;
                    if(mp[5] < 0 || mp[10] < 0) return false;
                }
            }
        }
        return true;
    }
};
