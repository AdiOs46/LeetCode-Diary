class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high) {
            int weight = (low + high)/2;
            int currw = 0, cdays = 1;

            for(int i=0; i<n; i++) {
                if(currw + weights[i] > weight) {
                    cdays++;
                    currw = weights[i];
                } else
                    currw += weights[i];
            }

            if(cdays > days) {
                low = weight + 1;
            } else 
                high = weight - 1;
        }
        return low;
    }
};
