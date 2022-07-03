// TC: O(NlogN), where N = size of the array
// SC: O(1)
class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        int erase_cnt = 0, prev_idx = 0;
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[prev_idx][1] > intervals[i][0]) erase_cnt++;
            else prev_idx = i;
        }
        
        return erase_cnt;
    }
};