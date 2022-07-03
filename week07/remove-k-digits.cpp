// TC: O(N)
// SC: O(N)
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        stk.push(num[0]);
        
        for (int i = 1; i < num.size(); i++) {
            while (k > 0 && !stk.empty() && stk.top() > num[i]) {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        
        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }        
        
        string result("");
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        while (!result.empty() && result.back() == '0') {
             result.pop_back();
        }

        reverse(result.begin(), result.end());

        if (result.empty()) return "0";
            
        return result;
    }
};