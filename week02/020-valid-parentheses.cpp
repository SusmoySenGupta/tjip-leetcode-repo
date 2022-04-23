// TC: O(N)
// SC: O(N)
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> ob;

        for (auto ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                ob.push(ch);
            }
            else
            {
                if (ob.empty() || (ob.top() == '(' && ch != ')') || (ob.top() == '{' && ch != '}') || (ob.top() == '[' && ch != ']'))
                    return false;
                ob.pop();
            }
        }

        return ob.empty();
    }
};