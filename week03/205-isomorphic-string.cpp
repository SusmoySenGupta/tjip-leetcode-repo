class Solution
{
public:
    bool isIsomorphic(string s, string t, int iteration_count = 0)
    {
        unordered_map<char, char> bucket;

        for (int i = 0; i < s.size(); i++)
        {
            if (bucket.count(s[i]) && bucket[s[i]] != t[i])
            {
                return false;
            }
            bucket[s[i]] = t[i];
        }

        if (iteration_count == 0)
        {
            return isIsomorphic(t, s, 1);
        }

        return true;
    }
};