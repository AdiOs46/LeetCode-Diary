class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int minDist = INT_MAX;
        int left=0, right=0;
        int n = cards.size();

        unordered_map<int, int> mp;

        for(right=0; right<n; right++) {
            if(mp.find(cards[right]) != mp.end())
                minDist = min(minDist, right - mp[cards[right]] + 1);
            mp[cards[right]] = right;
        }

        if(minDist == INT_MAX) return -1;
        return minDist;

    }
};
