class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if(n == 0) return 0;
        vector<int> isVisited(n, 0);
        int ans=0;
        
        for(int i=0; i<n; i++) {
            if(isVisited[i] == 0) {
                ans++;
                dfs(isConnected, isVisited, i);
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& isConnected, vector<int>& isVisited, int i) {
        isVisited[i] = 1;
        for(int j=0; j<isConnected.size(); j++)
            if(isConnected[i][j] == 1 && isVisited[j] == 0)
                dfs(isConnected, isVisited, j);
    }
};
