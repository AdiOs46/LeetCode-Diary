class Solution {
public:
    double myPow(double x, int n) {
         if (n == INT_MAX) 
            return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) 
            return (x == 1 || x == -1) ? 1 : 0;
        
        double ans = 1;
        if(n < 0) {
            n = -n;
            ans = pow(x, n);
            ans = 1.0/ans;
        }else ans = pow(x, n);
        
        return ans;
    }

    double pow(double x, int n) {
        if(n <= 0) return 1;
        return x * pow(x, n-1);
    }
};
