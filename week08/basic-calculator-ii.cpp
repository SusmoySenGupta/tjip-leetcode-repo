// TC: O(N)
// SC: O(1)
class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        if (!len) return 0;
        
        int curr_num = 0;
        int last_num = 0;
        int res = 0;
        char sign = '+';
        
        for (int i = 0; i < len; i++) {
            char curr_char = s[i];
            if (isdigit(curr_char)) {
                curr_num = (curr_num * 10) + (curr_char - '0');
            }
            if (!isdigit(curr_char) && !iswspace(curr_char) || i == len - 1) {
                if (sign == '+' || sign == '-') {
                    res += last_num;
                    last_num = (sign == '+') ? curr_num : -curr_num;
                } else if (sign == '*') {
                    last_num = last_num * curr_num;
                } else if (sign == '/') {
                    last_num = last_num / curr_num;
                }
                sign = curr_char;
                curr_num = 0;
            }
        }
        
        res += last_num;
        
        return res;
    }
};