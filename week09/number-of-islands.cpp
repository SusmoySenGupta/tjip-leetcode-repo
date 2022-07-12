// TC: O(N), where N = number of nodes
// TC: O(1)
class Solution {
public:
    static constexpr char WATER = '0';
    static constexpr char LAND = '1';
    static constexpr char VISITED = '2';
    static constexpr int DIRS[5] = {0, 1, 0, -1, 0};
    int N, M;
    
    bool canMove(vector<vector<char>> &grid, int X, int Y) {
        return X >= 0 && X < N && Y >= 0 && Y < M;
    }
    
    void traverse(vector<vector<char>> &grid, int SX, int SY) {
        grid[SX][SY] = VISITED;
        for (int i = 0; i < 4; i++) {
            int DX = SX + DIRS[i];
            int DY = SY + DIRS[i + 1];
            if (canMove(grid, DX, DY) && grid[DX][DY] == LAND) {
                traverse(grid, DX, DY);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        N = grid.size();
        M = grid[0].size();
        int island_count = 0;
        
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (grid[row][col] == LAND) {
                    traverse(grid, row, col);
                    island_count++;
                }
            }
        }
        
        return island_count;
    }
};