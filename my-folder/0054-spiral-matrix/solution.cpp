class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        int row_min = 0, row_max = n - 1;
        int col_min = 0, col_max = m - 1;

        while(row_min <= row_max && col_min <= col_max) {
            
            for(int col = col_min; col <= col_max; col++) {
                ans.push_back(matrix[row_min][col]);
            }
            row_min++;

            for(int row = row_min; row <= row_max; row++) {
                ans.push_back(matrix[row][col_max]);
            }
            col_max--;

            if(row_min <= row_max) {
                for(int col = col_max; col >= col_min; col--) {
                    ans.push_back(matrix[row_max][col]);
                }
                row_max--;
            }

            if(col_min <= col_max) {
                for(int row = row_max; row >= row_min; row--) {
                    ans.push_back(matrix[row][col_min]);
                }
                col_min++;
            }
        }

        return ans;
    }
};
