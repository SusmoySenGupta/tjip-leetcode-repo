// TC: O(logN), 
// SC: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n;
        
        while(L < R) {
            int mid = L + (R-L)/2;
            if(isBadVersion(mid)) R = mid;
            else L = mid + 1;
        }
        
        return L;
    }
};