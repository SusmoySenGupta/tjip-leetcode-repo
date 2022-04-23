// TC: O(N)
// SC: O(1)
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> freq(256, 0);
        int L = 0, R = 0, count = 0;
        int longestLength = 0;

        while (R < s.size())
        {
            freq[s[R]]++;
            if (freq[s[R]] > 1)
                count++;
            R++;
            while (count > 0)
            {
                freq[s[L]]--;
                if (freq[s[L]] == 1)
                    count--;
                L++;
            }
            longestLength = max(longestLength, R - L);
        }

        return longestLength;
    }
};