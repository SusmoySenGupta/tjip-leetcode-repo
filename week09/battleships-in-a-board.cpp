// TC: O(N)
// SC: O(1)
class Solution {
public:
    static constexpr char SHIP = 'X';
    static constexpr char EMPTY = '.';
    static constexpr char VISITED = '#';
    static constexpr int DIRS[3] = {1, 0, 1};
    int N, M;
    
    bool canMove(vector<vector<char>>& board, int X, int Y) {
        return X >= 0 && X < N && Y >= 0 && Y < M && board[X][Y] == SHIP;
    }
    
    void traverse(vector<vector<char>>& board, int SX, int SY) {
        board[SX][SY] = VISITED;
        for (int i = 0; i < 2; i++) {
            int DX = SX + DIRS[i];
            int DY = SY + DIRS[i + 1];
            if (canMove(board, DX, DY)) traverse(board, DX, DY);
        }
    }
    
    int countBattleships(vector<vector<char>>& board) {
        N = board.size();
        M = board[0].size();
        int ship_count = 0;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (board[row][col] == SHIP) {
                    traverse(board, row, col);
                    ship_count++;
                }
            }
        }
        return ship_count;
    }
};