class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        vector<bool> arr(n+1, true);
        int count=0;
        arr[0] = arr[1] = false;
        for(int i=2;i*i<=n; i++) {
            if(arr[i]) {
                for(int j=i*i; j<=n; j+=i) {
                    arr[j] = false;
                }
            }
        }

        for (int i = 2; i < n; i++)
            if (arr[i]) count++;

        return count;
    }
};
