class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        int countOne=0;

        for(int i=0; i<mat.size(); i++)
            for(int j=0; j<mat[0].size(); j++)
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
        
        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            int size = q.size();
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy] : dirs)  {
                int nx = x + dx;
                int ny = y + dy;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && ans[nx][ny] == -1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    return ans;
    }
};
