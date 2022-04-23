// TC: O(N)
// SC: O(N)
class Solution
{
public:
    int MOD = 1e9 + 7;
    int BASE = 29;
    vector<long long> prefixHash;
    vector<long long> powers;

    void preprocess(string &haystack)
    {
        prefixHash[0] = haystack[0];

        for (int i = 1; i < haystack.size(); i++)
        {
            prefixHash[i] = (prefixHash[i - 1] * BASE) % MOD;
            prefixHash[i] += haystack[i];
            powers[i] = (powers[i - 1] * BASE) % MOD;
        }
    }

    long long getRangeHash(int L, int R)
    {
        long long x1 = prefixHash[R];
        long long x2 = L == 0 ? 0 : (prefixHash[L - 1] * powers[R - L + 1]) % MOD;
        return (x1 - x2 + MOD) % MOD;
    }

    long long generateHash(string &needle)
    {
        long long hash = 0;
        for (auto ch : needle)
        {
            hash = (hash * BASE) + ch;
            hash %= MOD;
        }
        return hash;
    }

    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        int sLen = s.size();
        int i = 0;
        string result("");

        prefixHash.resize(sLen + 1, 0);
        powers.resize(sLen + 1, 1);
        preprocess(s);

        map<int, pair<string, string>> replace;

        for (int i = 0; i < indices.size(); i++)
        {
            replace[indices[i]] = {sources[i], targets[i]};
        }

        while (i < sLen)
        {
            if (replace.count(i) != 0)
            {
                int sourceLen = replace[i].first.size();
                long long sourceHash = generateHash(replace[i].first);
                if (getRangeHash(i, i + sourceLen - 1) == sourceHash)
                {
                    result += replace[i].second;
                    i += sourceLen;
                }
                else
                {
                    result += s[i];
                    i++;
                }
            }
            else
            {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};