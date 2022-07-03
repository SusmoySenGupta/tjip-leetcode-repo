// TC: O(logN)
// SC: O(1)
class Solution {
public:
    int mySqrt(int x) {
        long long L = 0, R = x;
        while(L < R) {
            long long M = L + (R-L+1)/2;
            if (M * M > x) R = M - 1;
            else L = M;
        }
        return L;
    }
};