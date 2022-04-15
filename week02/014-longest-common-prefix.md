### 792. [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) `Easy` :seedling:

---

#### Explanation

-   Started traversing the first string. And checked if the character of the first string is present in other strings.
-   If the character is present in all strings, then I concatenated the character to the `longest_prefix` string. Otherwise, I broke the loop and returned the `longest_prefix`.

#### Complexity

**Time:** `O(N * S)` where, N = total number of strings, S = smallest string.

**Space:** `O(1)`

#### Code

```cpp
string longestCommonPrefix(vector<string>& strs) {
    string longest_prefix = "";

    for(int i=0; i < strs[0].size(); i++) {
        for(int j=1; j < strs.size(); j++) {
            if(strs[j][i] != strs[0][i]) {
                return longest_prefix;
            }
        }
        longest_prefix += strs[0][i];
    }

    return longest_prefix;
}
```
