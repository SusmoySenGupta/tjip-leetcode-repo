// TC: O(N)
// SC: O(N)
class Solution
{
public:
    string stackToString(stack<char> &st)
    {
        string str = "";
        while (!st.empty())
        {
            str = st.top() + str;
            st.pop();
        }
        return str;
    }

    string decodeString(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string substr = "";
                while (st.top() != '[')
                {
                    substr = st.top() + substr;
                    st.pop();
                }
                st.pop();
                string number = "";
                while (!st.empty() && isdigit(st.top()))
                {
                    number = st.top() + number;
                    st.pop();
                }
                int k_time = stoi(number);
                while (k_time--)
                {
                    for (int i = 0; i < substr.size(); i++)
                        st.push(substr[i]);
                }
            }
        }

        return stackToString(st);
    }
};