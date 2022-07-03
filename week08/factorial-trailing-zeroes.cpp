// TC: O(logN)
// SC: O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        int zeros_cnt = 0;
        for (int i = 5; n / i >= 1; i *= 5) {
            zeros_cnt += n/i;
        }
        return zeros_cnt;
    }
};