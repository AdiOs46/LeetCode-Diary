class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = 0, ptr2 = 0;
        vector<int> temp;
        
        while(ptr1 < m && ptr2 < n) {
            if(nums1[ptr1] < nums2[ptr2])
                temp.push_back(nums1[ptr1++]);
            else
                temp.push_back(nums2[ptr2++]);
        }

        while(ptr1 < m) temp.push_back(nums1[ptr1++]);
        while(ptr2 < n) temp.push_back(nums2[ptr2++]);

        nums1 = temp;
    }
};
