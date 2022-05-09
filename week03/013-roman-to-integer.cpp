// TC: O(N)
// SC: O(1)
class Solution
{
public:
    unordered_map<char, int> symbol_value;

    Solution()
    {
        symbol_value['I'] = 1;
        symbol_value['V'] = 5;
        symbol_value['X'] = 10;
        symbol_value['L'] = 50;
        symbol_value['C'] = 100;
        symbol_value['D'] = 500;
        symbol_value['M'] = 1000;
    }

    int romanToInt(string s)
    {
        int sum = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int firstNumber = symbol_value[s[i]], secondNumber = 0;

            if (i + 1 < s.length())
            {
                secondNumber = symbol_value[s[i + 1]];
            }
            if (firstNumber < secondNumber)
            {
                sum += (secondNumber - firstNumber);
                i++;
            }
            else
            {
                sum += firstNumber;
            }
        }

        return sum;
    }
};