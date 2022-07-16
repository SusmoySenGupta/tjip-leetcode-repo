// Author: Susmoy Sen Gupta
// TC: O(N)
// SC: O(1)
class Solution {
public:
    static constexpr int WHITE = '0';
    static constexpr int BLACK = '1';
    static constexpr int VISITED = '2';
    static constexpr int DIRS[5] = {0, 1, 0, -1, 0};
    int N, M, top, bottom, left, right;
    
    bool canMove(vector<vector<char>> &img, int X, int Y) {
        return X >= 0 && X < N && Y >= 0 && Y < M && img[X][Y] == BLACK;
    }
    
    void traverse(vector<vector<char>> &img, int SX, int SY) {
        img[SX][SY] = VISITED;
        top = min(top, SX);
        left = min(left, SY);
        bottom = max(bottom, SX + 1);
        right = max(right, SY + 1);
        for (int i = 0; i < 4; i++) {
            int DX = SX + DIRS[i];
            int DY = SY + DIRS[i + 1];
            if (canMove(img, DX, DY)) traverse(img, DX, DY);
        }
    }
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        N = image.size();
        M = image[0].size();
        top = bottom = x;
        left = right = y;
        traverse(image, x, y);
        return (bottom - top) * (right - left);
    }
};