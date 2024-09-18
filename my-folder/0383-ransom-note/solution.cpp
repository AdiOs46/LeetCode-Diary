class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp; 
        for(auto s : magazine) 
            mp[s]++;

        for(auto it : ransomNote) {
            if(mp.find(it) != mp.end() && mp[it] > 0)
                mp[it]--;
            else
                return false;
        }

        return true;
    }
};
