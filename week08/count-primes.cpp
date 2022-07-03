// TC: O(N log(logN))
// SC: O(N)
class Solution {
private:
    void seieve(vector<bool> &comp, int &n) {
        comp[1] = true;
        for(int i = 2; i*i <= n; i++) {
            if(comp[i] == false) {
                for(int j = i*i; j <= n; j += i) {
                    comp[j] = true;
                }
            }
        }
    }
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> comp(n+1, false);
        seieve(comp, n);
        
        int prime_cnt = 1;
        for(int i = 3; i <= n; i+=2) {
            if(!comp[i]) prime_cnt++;
        }
        
        return prime_cnt;
    }
};