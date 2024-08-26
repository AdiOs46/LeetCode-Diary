class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;

        int low = 0, high = m-1;
        int chosenRow = 0;
        while(low <= high) {
            int mid = (low + high)/2;
            if(target < matrix[mid][0])
                high = mid-1;
            else if(target > matrix[mid][n-1])
                low = mid+1;
            else {
                chosenRow = mid;
                break;
            }
        }

        low=0, high = n-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(matrix[chosenRow][mid] == target) return true;
            
            if(matrix[chosenRow][mid] < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }

        return false;
    }
};
