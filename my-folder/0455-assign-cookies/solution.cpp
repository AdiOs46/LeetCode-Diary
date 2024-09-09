class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gpt = 0, cpt = 0, n = g.size(), m = s.size();
        int count = 0;

        while(gpt < n && cpt < m)  {
            if(g[gpt] <= s[cpt]) {
                count++;
                gpt++;
            } 
            cpt++;
        }
        return count;
    }
};
