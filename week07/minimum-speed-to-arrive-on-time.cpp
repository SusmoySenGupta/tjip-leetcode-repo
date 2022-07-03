// TC: O(NlogN)
// SC: O(1)
class Solution {
private: 
    bool canReach(vector<int> &dist, double hour, int speed) {
        double time_need = 0;
        
        for (int i = 0; i < dist.size() - 1; i++) {
            time_need += ceil((double)dist[i]/speed);
        }
        time_need += (double) dist.back() / speed;
        
        return time_need <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > ceil(hour)) return -1;
        
        int L = 1, R = 1e7;
        while (L <= R) {
            int M = L + (R-L)/2;
            if (canReach(dist, hour, M)) {
                R = M-1;
            } else {
                L = M+1;
            }
        }
        
        return L;
    }
};