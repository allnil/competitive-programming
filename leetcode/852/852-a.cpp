class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        while (start < end) { 
            int m = start + (end - start) / 2;
            if (arr[m] < arr[m + 1]) { 
                start = m + 1;
            } else { 
                end = m;
            }
        }
        
        return start; 
    }
};