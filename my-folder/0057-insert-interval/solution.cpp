class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};

        int n = intervals.size();
        int low = 0, high = n - 1;

        int lowerBound = -1, upperBound = -1;

        // Lower bound search
        while (low <= high) {
            int mid = (low + high) / 2;

            if (newInterval[0] >= intervals[mid][0] && newInterval[0] <= intervals[mid][1]) {
                lowerBound = mid;
                break;
            } else if (newInterval[0] > intervals[mid][1])
                low = mid + 1;
            else
                high = mid - 1;
        }

        if (lowerBound == -1) lowerBound = low;

        low = lowerBound, high = n - 1;

        // Upper bound search
        while (low <= high) {
            int mid = (low + high) / 2;

            if (newInterval[1] >= intervals[mid][0] && newInterval[1] <= intervals[mid][1]) {
                upperBound = mid;
                break;
            } else if (newInterval[1] > intervals[mid][1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (upperBound == -1) upperBound = high;
        int newLow, newHigh;

        if(lowerBound < n && newInterval[0] >= intervals[lowerBound][0])
            newLow = intervals[lowerBound][0];
        else 
            newLow = newInterval[0];

        if(upperBound >= 0 && newInterval[1] <= intervals[upperBound][1])
            newHigh = intervals[upperBound][1];
        else 
            newHigh = newInterval[1];

        if (lowerBound <= upperBound) 
            intervals.erase(intervals.begin() + lowerBound, intervals.begin() + upperBound + 1);
        intervals.insert(intervals.begin() + lowerBound, {newLow, newHigh});

        return intervals;
    }
};
