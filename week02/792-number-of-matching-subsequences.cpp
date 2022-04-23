// TC:  O(M * logN) where, M = total number of characters in all strings, N = average frequency of each character.
// SC: O(N)
class Solution
{
public:
    bool isSubsequence(string word, vector<vector<int>> &freq)
    {
        int prevPosition = -1;
        for (auto &ch : word)
        {
            auto nextPosition = upper_bound(freq[ch].begin(), freq[ch].end(), prevPosition);
            if (nextPosition == freq[ch].end())
            {
                return false;
            }
            prevPosition = *nextPosition;
        }
        return true;
    }

    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<vector<int>> freq(257, vector<int>());
        int noSubseq = 0;
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]].push_back(i);
        }
        for (auto &word : words)
        {
            noSubseq += isSubsequence(word, freq);
        }
        return noSubseq;
    }
};