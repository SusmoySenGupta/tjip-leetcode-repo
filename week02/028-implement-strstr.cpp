// TC: O(N)
// SC: O(N)
class Solution
{
public:
    int BASE = 29;
    int MOD = 1e9 + 7;
    vector<long long> prefixHash, powerHash;

    void preprocess(string &haystack)
    {
        prefixHash[0] = haystack[0];

        for (int i = 1; i < haystack.size(); i++)
        {
            prefixHash[i] = (prefixHash[i - 1] * BASE) % MOD;
            prefixHash[i] += haystack[i];
            powerHash[i] = (powerHash[i - 1] * BASE) % MOD;
        }
    }

    long long getRangeHash(int L, int R)
    {
        long long x1 = prefixHash[R];
        long long x2 = L == 0 ? 0 : (prefixHash[L - 1] * powerHash[R - L + 1]) % MOD;

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

    int strStr(string haystack, string needle)
    {
        int HL = haystack.size();
        int NL = needle.size();

        prefixHash.resize(HL + 1, 0);
        powerHash.resize(HL + 1, 1);
        preprocess(haystack);

        long long needleHash = generateHash(needle);

        for (int i = 0; i <= (HL - NL); i++)
        {
            if (getRangeHash(i, i + NL - 1) == needleHash)
            {
                return i;
            }
        }

        return -1;
    }
};