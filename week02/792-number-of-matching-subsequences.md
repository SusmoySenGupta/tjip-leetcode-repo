### 792. [ Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/) `Medium` :fire:

---

#### Explanation

-   In the very beginning, I kept positions of each character of the string `s` in a 2D array.
-   Then I started traversing the `words` array. For each character of a word, I looked up the positions of the character in the `seen` array by using `upperBound` technique.
-   If the `newPosition` is less than the `prevPosition`, then the word is not a subsequence of the string `s`. So I broke the loop and and made the `flag` false.
-   After checking all the character of a word, if the `flag` was _true_, then I incremented the `matchingSubsequence` by 1.

#### Complexity

**Time:** `O(M * N logN)` where, M = No of Words and N = No of characters in each Word.

**Space:** `O(N)`

#### Code

```cpp
int upperBound(vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (target >= arr[mid]) left = mid + 1;
        else right = mid - 1;
    }

    return left;
}

int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> seen(257, vector<int>());
    int matchingSubsequence = 0;

    for(int i = 0; i < s.size(); i++) {
        seen[s[i]].push_back(i);
    }

    for(auto &word : words) {
        int prevPosition = -1;
        bool flag = true;

        for(auto &ch : word) {
            if(seen[ch].empty()) { flag = false; break; }

            int pos = upperBound(seen[ch], prevPosition);
            if(pos >= seen[ch].size()) { flag = false; break; }

            int newPosition = seen[ch][pos];
            if(newPosition < prevPosition) { flag = false; break; }

            prevPosition = newPosition;
        }

        if(flag) matchingSubsequence++;
    }

    return matchingSubsequence;
}
```
