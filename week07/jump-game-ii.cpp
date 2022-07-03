// TC: O(N), where N = size of the array
// SC: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int min_jump = 0;
        int L = 0;
        int R = 0;
        
        while(R < nums.size() - 1) {
            int furthest = 0;
            for(int i = L; i <= R; i++) {
                furthest = max(furthest, i + nums[i]);
            }
            L = R+1;
            R = furthest;
            min_jump++;
        }
        
        return min_jump;
    }
};