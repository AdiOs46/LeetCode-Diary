class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < (long)m * k) return -1;

        int low = 1, high = 1e9;
        

        while (low <= high) {
            int mid = (low + high)/2;
            int bouq = 0, flow = 0;
            
            for(int i=0; i<n; i++) {
                if(bloomDay[i] <= mid) {
                    flow++;
                    if(flow == k) {
                        bouq++;
                        flow = 0;
                    }
                } else flow = 0;
            }

            if(bouq < m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
