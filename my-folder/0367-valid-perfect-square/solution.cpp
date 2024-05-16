class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        long long low=2, high=num;
        
        while(low <= high) {
            long long mid = low + (high-low)/2;
            long long ans = mid * mid;
            if(ans == num) return true;
            
            if(ans > num) 
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
        
    }
};
