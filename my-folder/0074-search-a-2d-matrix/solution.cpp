class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0, high = matrix.size()-1;
        int chosenRow = -1;

        if (target > matrix[high][matrix[high].size()-1]) return false;
        if (target < matrix[low][0]) return false;

        while(low <= high) {
            int mid = low+(high - low)/2;
            int midLastEle = matrix[mid].size() - 1;
            
            if(matrix[mid][0] <= target && matrix[mid][midLastEle] >= target) {
                chosenRow = mid;
                break;
            } else if(matrix[mid][midLastEle] > target)
                high = mid-1;
            else 
                low = mid+1;
        }
        
        if(chosenRow == -1) return false;
        low=0, high = matrix[chosenRow].size()-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(matrix[chosenRow][mid] == target) 
                return true;
            else if(matrix[chosenRow][mid] > target) 
                high = mid-1;
            else 
                low= mid+1;
        }
        return false;
    }
};
