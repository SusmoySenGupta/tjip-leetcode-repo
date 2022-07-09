// Author: Susmoy Sen Gupta
// TC: O(N+M)
// SC: O(N)
class Solution {
public:
    static constexpr int WALL = -1;
    static constexpr int GATE = 0;
    static constexpr int dir[5] = {0, 1, 0, -1, 0};
    
    bool isValidMove(int X, int N, int Y, int M) {
        return X >= 0 && X < N && Y >= 0 && Y < M;
    }
        
    void wallsAndGates(vector<vector<int>>& rooms) {
        int N = rooms.size();
        int M = rooms[0].size();
        queue<pair<int, int>> Q;
        
        for (int r = 0; r < N; r++) 
        {
            for (int c = 0; c < M; c++) 
            {
                if (rooms[r][c] == GATE) Q.push({r, c});
            }
        }
        
        while (!Q.empty()) 
        {
            auto U = Q.front();
            int UX = U.first, UY = U.second;
            Q.pop();
            for (int i = 0; i < 4; i++) 
            {
                int X = UX + dir[i];
                int Y = UY + dir[i + 1];
                if (isValidMove(X, N, Y, M)) 
                {
                    int newDist = rooms[UX][UY] + 1;
                    if (newDist < rooms[X][Y]) {
                        rooms[X][Y] = newDist;
                        Q.push({X, Y});
                    }
                }   
            }
        }
        
        return;
    }
};