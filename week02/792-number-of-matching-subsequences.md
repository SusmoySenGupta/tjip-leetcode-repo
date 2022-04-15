### 792. [ Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/) `Medium` :fire:

---

#### Explanation

-   In the very beginning, I kept positions of each character of the string `s` in a 2D array.
-   Then I started traversing the `words` array. For each character of a word, I looked up the positions of the character in the `seen` array by using `upperBound` technique.
-   If the `newPosition` is less than the `prevPosition`, then the word is not a subsequence of the string `s`. So I broke the loop and and made the `flag` false.
-   After checking all the character of a word, if the `flag` was _true_, then I incremented the `matchingSubsequence` by 1.

#### Complexity

**Time:** `O(M * logN)` where, M = total number of characters in all strings, N = average frequency of each character.

**Space:** `O(N)` where, N = number of characters in the string `s`.

#### Code

```cpp
bool isSubsequence(string word, vector<vector<int>>& freq) {
    int prevPosition = -1;
    for(auto &ch : word) {
        auto nextPosition = upper_bound(freq[ch].begin(), freq[ch].end(), prevPosition);
        if (nextPosition == freq[ch].end()) {
            return false;
        }
        prevPosition = *nextPosition;
    }
    return true;
}

int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> freq(257, vector<int>());
    int noSubseq = 0;
    for(int i = 0; i < s.size(); i++) {
        freq[s[i]].push_back(i);
    }
    for(auto &word : words) {
        noSubseq += isSubsequence(word, freq);
    }
    return noSubseq;
}
```
