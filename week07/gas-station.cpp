// TC: O(N)
// SC: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start_index = 0;
        int total_tank = 0;
        int curr_tank = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            int curr = gas[i] - cost[i];
            curr_tank += curr;
            total_tank += curr;
            
            if (curr_tank < 0) {
                start_index = i+1;
                curr_tank = 0;
            }
        }
        
        if (total_tank < 0) start_index = -1;
        
        return start_index;
    }
};
