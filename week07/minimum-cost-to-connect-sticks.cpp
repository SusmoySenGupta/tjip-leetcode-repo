// Author: Susmoy Sen Gupta

// TC: O(N logN)
// SC: O(N)
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int total_cost = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for (auto &stick: sticks) min_heap.push(stick);
        
        while (min_heap.size() > 1) {
            int stick1 = min_heap.top();
            min_heap.pop();
            int stick2 = min_heap.top();
            min_heap.pop();
            
            int cost = stick1 + stick2;
            min_heap.push(cost);
            
            total_cost += cost;
        }
        
        return total_cost;
    }
};