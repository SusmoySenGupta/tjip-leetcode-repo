// TC: O(N)
// SC: O(N)
class Solution
{
public:
    unsigned long long getHash(string &str)
    {
        unsigned long long hash = 1;
        for (auto c : str)
        {
            hash = (hash * (257 + (c - 'a')));
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<unsigned long long, vector<string>> bucket;
        vector<vector<string>> anagrams;

        for (auto &str : strs)
        {
            bucket[getHash(str)].push_back(str);
        }

        for (auto &item : bucket)
        {
            anagrams.push_back(item.second);
        }

        return anagrams;
    }
};