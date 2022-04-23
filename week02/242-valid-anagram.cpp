// TC: O(N)
// SC: O(N)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<int, int> bucket;

        for (int i = 0; i < s.size(); i++)
        {
            bucket[s[i]]++;
            bucket[t[i]]--;
        }

        for (auto bkt : bucket)
        {
            if (bkt.second != 0)
                return false;
        }

        return true;
    }
};