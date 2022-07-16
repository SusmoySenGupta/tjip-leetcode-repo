// TC: O(N + M), where N = number of nodes, M = number of edges
// SC: O(N + M)
class Solution {
public:
    vector<vector<int>> graph;
    
    int findMinutes(vector<int> &informTime, int U) {
        int max_time_need = 0;
        for (auto &V : graph[U]) {
            max_time_need = max(max_time_need, findMinutes(informTime, V));
        }
        return max_time_need + informTime[U];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        graph.clear();
        graph.resize(n + 1);
        for(int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }
        return findMinutes(informTime, headID);
    }
};