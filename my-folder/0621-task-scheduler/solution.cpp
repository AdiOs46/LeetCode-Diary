class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        for (char task : tasks) taskCount[task]++;
        
        priority_queue<int> maxHeap;
        for (auto& pair : taskCount) maxHeap.push(pair.second);
        
        int intervals = 0;
        queue<pair<int, int>> cooldown;

        while (!maxHeap.empty() || !cooldown.empty()) {
            intervals++;

            if (!maxHeap.empty()) {
                int currentTaskCount = maxHeap.top();
                maxHeap.pop();
                if (currentTaskCount > 1) cooldown.push({currentTaskCount - 1, intervals + n});
            }

            if (!cooldown.empty() && cooldown.front().second == intervals) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return intervals;
    }
};
