// TC: O(log (M + N)), where M & N are length of nums1 & nums2
// SC: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {      
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        
        int L = 0, R = n1;
        
        while (L <= R) {
            int M1 = (L+R) / 2;
            int M2 = ((n1 + n2 + 1) / 2) - M1;
            
            int L1 = M1 == 0 ? INT_MIN : nums1[M1-1];
            int L2 = M2 == 0 ? INT_MIN : nums2[M2-1];
            
            int R1 = M1 == n1 ? INT_MAX : nums1[M1];
            int R2 = M2 == n2 ? INT_MAX : nums2[M2];
            
            if (L1 <= R2 && L2 <= R1) {
                if ((n1 + n2) % 2 == 0) {
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                } else {
                    return max(L1, L2);
                }
            } else if (L1 > R2) {
                R = M1 - 1;
            } else {
                L = M1 + 1;
            }
        }
        
        return 0.0;
    }
};