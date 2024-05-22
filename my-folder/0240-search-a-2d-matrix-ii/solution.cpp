class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int firstRowSize = matrix[0].size();
        int row = 0, col = firstRowSize-1;

        while(row < matrix.size() && col >= 0) {
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] > target)
                col--;
            else 
                row++;
        }
        return false;
    }
};
