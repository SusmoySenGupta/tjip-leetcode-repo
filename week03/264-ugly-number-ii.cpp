// TC: O(N)
// SC: O(N)
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        set<long long> possible_nums, fix;

        possible_nums.insert(1);

        while (fix.size() != n)
        {
            long long nextUgly = *possible_nums.begin();

            fix.insert(nextUgly);
            possible_nums.erase(nextUgly);

            possible_nums.insert(2 * nextUgly);
            possible_nums.insert(3 * nextUgly);
            possible_nums.insert(5 * nextUgly);
        }

        return *fix.rbegin();
    }
};