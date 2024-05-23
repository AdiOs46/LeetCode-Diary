class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        map<char, int> mp;
        vector<char> letter;
        vector<int> freq;
        int maxEle = -1;

        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            letter.push_back(it->first);
            freq.push_back(it->second);
        }

        for(int i=0; i<freq.size(); i++){
            for(int j=0; j<freq.size()-i-1; j++) {
                if (freq[j] > freq[j+1]) {
                    swap(freq[j],freq[j+1]);
                    swap(letter[j], letter[j+1]);
                }
            }
        }

        for(int i=freq.size()-1; i>=0; i--) {
            for(int j=0; j<freq[i]; j++)
                ans += letter[i];
        }

        return ans;
    }
};
