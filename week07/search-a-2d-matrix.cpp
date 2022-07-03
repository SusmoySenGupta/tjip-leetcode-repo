// TC: O(logM + logN), where M = size of rows and N = size of columns
// SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L = 0, R = (matrix.size() * matrix[0].size()) - 1;
        
        while(L <= R) {
            int M = L + (R - L)/2;
            
            int r = M / matrix[0].size();
            int c = M % matrix[0].size();
            
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) L = M + 1;
            else R = M - 1;
        }
        
        return false;
    }
};