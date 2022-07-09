// TC: O(N + M)
// SC: O(N + M)
class Solution {
public:
    static constexpr int NOT_VISITED = 0;
    static constexpr int IN_PROCESS = 1;
    static constexpr int COMPLETED = 2;
    
    vector<int> col;

    bool hasCycle(vector<vector<int>> &graph, int U) {
        col[U] = IN_PROCESS;
        bool isCycle = false;
        for (auto &v : graph[U]) {
            if (col[v] == IN_PROCESS) isCycle = true;
            else if (col[v] == NOT_VISITED) isCycle |= hasCycle(graph, v);
        }
        col[U] = COMPLETED;
        return isCycle;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        col.clear();
        col.resize(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        
        for (auto &prerequisite : prerequisites) {
            int u = prerequisite[0];
            int v = prerequisite[1];
            graph[u].push_back(v);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (col[i] == NOT_VISITED && hasCycle(graph, i)) {
                return false;
            }
        }
        
        return true;
    }
};