class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image; 
        int m = image.size();
        int n = image[0].size();
        vector<pair<int, int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int, int>> q;
        int oldColor = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr, sc});
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy] : dir)  {
                int nx = dx + x;
                int ny = dy + y; 
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == oldColor) {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};
