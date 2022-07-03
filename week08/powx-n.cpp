// TC: O(logN)
// SC: O(1)
class Solution {
private:
    double modExpo(double x, long long n) {
        if (n == 0) return 1.0;
        if (n%2 == 0) {
            auto temp = modExpo(x, n / 2);
            return (temp * temp);
        }
        return x * modExpo(x, n-1);
    }
public:
    double myPow(double x, int n) {
        bool isNeg = n < 0;
        if (n == 0) return 1.0;
        double bn = isNeg ? (1LL * (-1) * n) : n;
        double res = modExpo(x, bn);
        return isNeg ? (1.0 / res) : res; 
    }
};