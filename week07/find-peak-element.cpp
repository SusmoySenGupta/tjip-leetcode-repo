// TC: O(logN), where N = size of the array
// SC: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        
        int L = 1;
        int R = n - 2;
        
        while(L <= R) {
            int M = L + (R-L)/2;
            if(nums[M] > nums[M-1] && nums[M] > nums[M+1]) return M;
            else if(nums[M] < nums[M-1]) R = M-1;
            else L = M+1;
        }
        
        return -1;
    }
};