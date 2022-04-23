// TC: O(N*S) where, N = total number of strings, S = smallest string.
// MC: O(1)
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string longest_prefix = "";

        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != strs[0][i])
                {
                    return longest_prefix;
                }
            }
            longest_prefix += strs[0][i];
        }

        return longest_prefix;
    }
};