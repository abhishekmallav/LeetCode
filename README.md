# LeetCode Solutions

A daily log of my LeetCode solutions, automatically updated on every submission.

<a href="https://leetcode.com/u/abhishekmallav/" target="_blank"><img src="https://img.shields.io/badge/LeetCode-abhishekmallav-FFA116?style=flat&logo=leetcode&logoColor=white" alt="LeetCode Profile"/></a>

---

<!-- SUBMISSIONS -->

<details>
<summary><h3>205. Isomorphic Strings</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 54.46%` `Commit:d35edaf` `Solved At: 2026-04-02 13:35:30` <code><a href="https://leetcode.com/problems/isomorphic-strings/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mapS(256, -1);
        vector<int> mapT(256, -1);

        for (int i = 0; i < s.size(); i++) {
            char charS = s[i];
            char charT = t[i];

            // If s[i] has been seen before, check if it maps to the same t[i]
            if (mapS[charS] != -1 && mapS[charS] != charT) {
                return false;
            }

            // If t[i] has been seen before, check if it maps to the same s[i]
            if (mapT[charT] != -1 && mapT[charT] != charS) {
                return false;
            }

            mapS[charS] = charT;
            mapT[charT] = charS;
        }

        return true;
    }
};
```

</details>


<details>
<summary><h3>202. Happy Number</h3></summary>

`Easy` `Time Beats: 15.95%` `Memory Beats: 20.84%` `Commit:f37d871` `Solved At: 2026-04-02 13:18:55` <code><a href="https://leetcode.com/problems/happy-number/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long> seen;
        long long num = n;

        while (num != 1) {
            if (seen.find(num) != seen.end()) {
                return false;
            }
            seen.insert(num);
            long long sum = 0;
            while (num > 0) {
                int digit = num % 10;
                sum += (digit * digit);
                num /= 10;
            }
            num = sum;
        }
        
        return true;
    }
};
```

</details>


<details>
<summary><h3>160. Intersection of Two Linked Lists</h3></summary>

`Easy` `Time Beats: 17.03%` `Memory Beats: 14.59%` `Commit:056127f` `Solved At: 2026-04-02 12:57:09` <code><a href="https://leetcode.com/problems/intersection-of-two-linked-lists/description/" target="_blank">LINK</a></code>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited; 

        ListNode* current = headA;
        while (current != nullptr) {
            visited.insert(current);
            current = current->next;
        }

        current = headB;
        while (current != nullptr) {
            if (visited.find(current) != visited.end()) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};
```

</details>


<details>
<summary><h3>141. Linked List Cycle</h3></summary>

`Easy` `Time Beats: 7.26%` `Memory Beats: 7.36%` `Commit:e1b72c7` `Solved At: 2026-04-02 12:49:49` <code><a href="https://leetcode.com/problems/linked-list-cycle/description/" target="_blank">LINK</a></code>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited; 

        ListNode* current = head;
        while (current != nullptr) {
            if (visited.find(current) != visited.end()) {
                return true;
            }
            visited.insert(current);
            current = current->next;
        }
        return false;
    }
};
```

</details>


<details>
<summary><h3>119. Pascal's Triangle II</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 50.68%` `Commit:6491eb2` `Solved At: 2026-04-02 11:58:45` <code><a href="https://leetcode.com/problems/pascals-triangle-ii/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        // nC0 is always 1
        long long current = 1;
        ans.push_back((int)current);
        
        // Formula to get nCi from nC(i-1)
        // Using long long to prevent overflow during multiplication
        for (int i = 1; i <= rowIndex; i++) {
            current = current * (rowIndex - i + 1) / i;
            ans.push_back((int)current);
        }
        
        return ans;
    }
};
```

</details>


<details>
<summary><h3>108. Convert Sorted Array to Binary Search Tree</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 20.32%` `Commit:e04da7f` `Solved At: 2026-04-02 11:40:54` <code><a href="https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    TreeNode* BST(vector<int>& nums, int L, int R) {
        if (L > R) {
            return nullptr;
        }
        
        int M = L + (R - L) / 2;
        
        TreeNode* root = new TreeNode(nums[M]);
        
        root->left = BST(nums, L, M - 1);
        root->right = BST(nums, M + 1, R);
        
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size() - 1);
    }
};
```

</details>


<details>
<summary><h3>3418. Maximum Amount of Money Robot Can Earn 🌟 POTD</h3></summary>

`Medium` `Time Beats: 67.24%` `Memory Beats: 83.83%` `Commit:a49895a` `Solved At: 2026-04-02 11:04:41` <code><a href="https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int m;
    int n;
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {
        if(i == m-1 && j == n-1) {
            if(coins[i][j] < 0 && neu > 0) {
                return 0;
            }

            return coins[i][j];
        }

        if(i >= m || j >= n) {
            return INT_MIN;
        }

        if(t[i][j][neu] != INT_MIN) {
            return t[i][j][neu];
        }

        int take = coins[i][j] + max(solve(coins, i+1, j, neu), solve(coins, i, j+1, neu));

        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0) {
            int skipDown = solve(coins, i+1, j, neu-1);
            int skipRight = solve(coins, i, j+1, neu-1);

            skip = max(skipDown, skipRight);
        }

        return t[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {

        m = coins.size();
        n = coins[0].size();

        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(coins, 0, 0, 2);
    }
};
```

</details>


<details>
<summary><h3>3474. Lexicographically Smallest Generated String</h3></summary>

`Hard` `Time Beats: 91.53%` `Memory Beats: 89.83%` `Commit:26b672f` `Solved At: 2026-03-31 13:05:57` <code><a href="https://leetcode.com/problems/lexicographically-smallest-generated-string/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    bool isSame(string& word, string& str2, int i, int m) {
        for (int j = 0; j < m; j++) {
            if (word[i] != str2[j]) {
                return false;
            }
            i++;
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        int N = n + m - 1;
        string word(N, '$');

        vector<bool> canChange(N, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                int j = i;
                for (int k = 0; k < m; k++) {
                    if (word[j] != '$' && word[j] != str2[k]) {
                        return "";
                    }
                    word[j] = str2[k];
                    j++;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (word[i] == '$') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {

                if (isSame(word, str2, i, m)) {

                    bool changed = false;
                    for (int k = i + m - 1; k >= i; k--) {
                        if (canChange[k] == true) {
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if (changed == false) {
                        return "";
                    }
                }
            }
        }

        return word;
    }
};
```

</details>


<details>
<summary><h3>2840. Check if Strings Can be Made Equal With Operations II</h3></summary>

`Medium` `Time Beats: 64.94%` `Memory Beats: 68.97%` `Commit:bac6533` `Solved At: 2026-03-30 16:53:56` <code><a href="https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even1(26, 0);
        vector<int> odd1(26, 0);
        vector<int> even2(26, 0);
        vector<int> odd2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            } else {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
        }

        if (even1 == even2 && odd1 == odd2) {
            return true;
        }
        return false;
    }
};
```

</details>


<details>
<summary><h3>2839. Check if Strings Can be Made Equal With Operations I 🌟 POTD</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 49.03%` `Commit:a497292` `Solved At: 2026-03-29 13:53:21` <code><a href="https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        string tmp = s1;
        swap(tmp[0], tmp[2]);
        if (tmp == s2) {
            return true;
        }
        swap(tmp[1], tmp[3]);
        if (tmp == s2) {
            return true;
        }
        swap(s1[1], s1[3]);
        if (s1 == s2) {
            return true;
        }
        return false;
    }
};
```

</details>


<details>
<summary><h3>2946. Matrix Similarity After Cyclic Shifts</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 49.69%` `Commit:c85c41c` `Solved At: 2026-03-27 10:02:52` <code><a href="https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k % n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int newIndex;

                // we are not actually shifting the elements but comparing the
                // new index if arr size is 3 and we have to rotate it 6 times
                // we dont need to rotate it at all
                // just check if the new index value with curr index

                if (i % 2 == 0) {
                    // left shift
                    newIndex = (j + k) % n;
                } else {
                    // right shift
                    newIndex = (j - k + n) % n;
                }

                if (mat[i][j] != mat[i][newIndex]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

</details>


<details>
<summary><h3>3548. Equal Sum Grid Partition II 🌟 POTD</h3></summary>

`Hard` `Time Beats: 60.00%` `Memory Beats: 58.46%` `Commit:1d3bdd5` `Solved At: 2026-03-26 20:14:07` <code><a href="https://leetcode.com/problems/equal-sum-grid-partition-ii/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    typedef long long ll;
    ll total = 0;

    bool checkHorCuts(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll> st;
        ll top = 0;

        for (int i = 0; i <= m - 2; i++) {

            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }

            ll bottom = (total - top);
            ll diff = top - bottom;

            if (diff == 0)
                return true;

            if (diff == (ll)grid[0][0])
                return true;
            if (diff == (ll)grid[0][n - 1])
                return true;
            if (diff == (ll)grid[i][0])
                return true;

            if (i > 0 && n > 1 && st.count(diff)) {
                return true;
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        if (checkHorCuts(grid)) {
            return true;
        }

        reverse(begin(grid), end(grid));

        if (checkHorCuts(grid)) {
            return true;
        }

        reverse(begin(grid), end(grid));
        vector<vector<int>> transposeGrid(n, vector<int>(m)); // n*m

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if (checkHorCuts(transposeGrid)) {
            return true;
        }

        reverse(begin(transposeGrid), end(transposeGrid));

        if (checkHorCuts(transposeGrid)) {
            return true;
        }

        return false;
    }
};
```

</details>


<details>
<summary><h3>3546. Equal Sum Grid Partition I 🌟 POTD</h3></summary>

`Medium` `Time Beats: 5.04%` `Memory Beats: 6.84%` `Commit:2e26111` `Solved At: 2026-03-25 18:45:10` <code><a href="https://leetcode.com/problems/equal-sum-grid-partition-i/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        long long prev = 0;
        vector<vector<long long>> HSum(row, vector<long long>(col, 0));
        vector<vector<long long>> VSum(row, vector<long long>(col, 0));

        // row wise cumulative sum
        if (row > 1) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    prev += grid[i][j];
                    HSum[i][j] = prev;
                }
            }
        }

        // column wise cumulative sum
        prev = 0;
        if (col > 1) {
            for (int i = 0; i < col; i++) {
                for (int j = 0; j < row; j++) {
                    prev += grid[j][i];
                    VSum[j][i] = prev;
                }
            }
        }

        long long total;
        if (row > 1) {
            total = HSum[row - 1][col - 1];
        } else {
            total = VSum[row - 1][col - 1];
        }

        // Horizontal cuts
        for (int i = 0; i < row - 1; i++) {
            if (HSum[i][col - 1] == total - HSum[i][col - 1]) {
                return true;
            }
        }

        // Vertical cuts
        for (int j = 0; j < col - 1; j++) {
            if (VSum[row - 1][j] == total - VSum[row - 1][j]) {
                return true;
            }
        }

        return false;
    }
};
```

</details>


<details>
<summary><h3>2906. Construct Product Matrix 🌟 POTD</h3></summary>

`Medium` `Time Beats: 22.14%` `Memory Beats: 7.75%` `Commit:7e3320c` `Solved At: 2026-03-24 09:48:35` <code><a href="https://leetcode.com/problems/construct-product-matrix/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    typedef long long ll;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD = 12345;
        int row = grid.size();
        int col = grid[0].size();

        ll prefixProduct = 1;
        ll suffixProduct = 1;

        vector<vector<ll>> prefix(row, vector<ll>(col, 1));
        vector<vector<ll>> suffix(row, vector<ll>(col, 1));
        vector<vector<int>> ans(row, vector<int>(col, 1));

        // prefix product
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                prefix[i][j] = prefixProduct;
                prefixProduct = (prefixProduct * grid[i][j]) % MOD;
            }
        }

        // suffix product
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                suffix[i][j] = suffixProduct;
                suffixProduct = (suffixProduct * grid[i][j]) % MOD;
            }
        }

        // prefixProduct[i][j]*suffixProduct[i][j]=ans[i][j]
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans[i][j] = (int)(prefix[i][j] * suffix[i][j]) % MOD;
            }
        }
        return ans;
    }
};
```

</details>


<details>
<summary><h3>1594. Maximum Non Negative Product in a Matrix 🌟 POTD</h3></summary>

`Medium` `Time Beats: 34.75%` `Memory Beats: 21.75%` `Commit:e14eef3` `Solved At: 2026-03-23 11:42:31` <code><a href="https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int m, n;
    typedef long long ll;
    int MOD = 1e9 + 7;

    vector<vector<pair<ll, ll>>> t;

    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if (t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
            return t[i][j];
        }

        // Down
        if (i + 1 < m) {
            auto [downMax, downMin] = solve(i + 1, j, grid);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        // Right
        if (j + 1 < n) {
            auto [rightMax, rightMin] = solve(i, j + 1, grid);
            maxVal =
                max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal =
                min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return t[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        t = vector<vector<pair<ll, ll>>>(
            m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        auto [maxProd, minProd] = solve(0, 0, grid);

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};
```

</details>


<details>
<summary><h3>1886. Determine Whether Matrix Can Be Obtained By Rotation 🌟 POTD</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 41.55%` `Commit:69b51fa` `Solved At: 2026-03-22 09:39:12` <code><a href="https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for (int c = 1; c <= 4; c++) {

            bool equal = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != target[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if (!equal)
                    break;
            }

            if (equal)
                return true;

            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }

            for (int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }
        }

        return false;
    }
};
```

</details>


<details>
<summary><h3>1010. Pairs of Songs With Total Durations Divisible by 60</h3></summary>

`Medium` `Time Beats: 100.00%` `Memory Beats: 72.80%` `Commit:7a0655e` `Solved At: 2026-03-21 11:33:28` <code><a href="https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        long long count = 0;
        vector<int> remainder(60, 0);

        for (int i = 0; i < n; i++) {
            int rem = time[i] % 60;
            remainder[rem]++;
        }

        for (int i = 1; i < 30; i++) {
            count += (long long)remainder[i] * remainder[60 - i];
        }

        if (remainder[0] > 1) {
            count += (long long)remainder[0] * (remainder[0] - 1) / 2;
        }

        if (remainder[30] > 1) {
            count += (long long)remainder[30] * (remainder[30] - 1) / 2;
        }

        return (int)count;
    }
};
```

</details>


<details>
<summary><h3>3643. Flip Square Submatrix Vertically 🌟 POTD</h3></summary>

`Easy` `Time Beats: 28.92%` `Memory Beats: 60.84%` `Commit:fcf83d1` `Solved At: 2026-03-21 09:24:30` <code><a href="https://leetcode.com/problems/flip-square-submatrix-vertically/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        vector<vector<int>> ans = grid;
        int L = x;
        int R = x + k - 1;
        while (L < R) {
            for (int i = y; i < y + k; i++) {
                swap(ans[L][i], ans[R][i]);
            }
            L++;
            R--;
        }
        return ans;
    }
};
```

</details>


<details>
<summary><h3>3567. Minimum Absolute Difference in Sliding Submatrix 🌟 POTD</h3></summary>

`Medium` `Time Beats: 88.89%` `Memory Beats: 68.15%` `Commit:74776ce` `Solved At: 2026-03-20 09:40:37` <code><a href="https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> ans(row - k + 1, vector<int>(col - k + 1, 0));
        if (k == 1) {
            return ans;
        }
        for (int i = 0; i <= row - k; i++) {
            for (int j = 0; j <= col - k; j++) {

                vector<int> tmp;

                // collect k x k subgrid
                for (int m = i; m < i + k; m++) {
                    for (int n = j; n < j + k; n++) {
                        tmp.push_back(grid[m][n]);
                    }
                }

                sort(tmp.begin(), tmp.end());
                auto it = unique(tmp.begin(), tmp.end());
                tmp.erase(it, tmp.end());
                
                if (tmp.size() < 2) {
                    ans[i][j] = 0;
                    continue;
                }

                int minDiff = INT_MAX;

                for (int o = 0; o < tmp.size() - 1; o++) {
                    int diff = abs(tmp[o] - tmp[o + 1]);
                    minDiff = min(minDiff, diff);

                    if (minDiff == 0) {
                        break;
                    }
                }

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};
```

</details>


<details>
<summary><h3>3212. Count Submatrices With Equal Frequency of X and Y 🌟 POTD</h3></summary>

`Medium` `Time Beats: 34.15%` `Memory Beats: 50.41%` `Commit:8a1adf0` `Solved At: 2026-03-19 09:55:56` <code><a href="https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> sum(row, vector<int>(col, 0));
        vector<vector<int>> countX(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                int val = 0;
                if (grid[i][j] == 'X') {
                    val = 1;
                } else if (grid[i][j] == 'Y') {
                    val = -1;
                }

                int xval = (grid[i][j] == 'X') ? 1 : 0;

                sum[i][j] = val;
                countX[i][j] = xval;

                if (i > 0) {
                    sum[i][j] += sum[i - 1][j];
                    countX[i][j] += countX[i - 1][j];
                }
                if (j > 0) {
                    sum[i][j] += sum[i][j - 1];
                    countX[i][j] += countX[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    sum[i][j] -= sum[i - 1][j - 1];
                    countX[i][j] -= countX[i - 1][j - 1];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (sum[i][j] == 0 && countX[i][j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
```

</details>


<details>
<summary><h3>3070. Count Submatrices with Top-Left Element and Sum Less Than k</h3></summary>

`Medium` `Time Beats: 79.21%` `Memory Beats: 74.72%` `Commit:742a40f` `Solved At: 2026-03-18 10:32:49` <code><a href="https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i > 0) {
                    grid[i][j] += grid[i - 1][j];
                }
                if (j > 0) {
                    grid[i][j] += grid[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    grid[i][j] -= grid[i - 1][j - 1];
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] <= k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

</details>


<details>
<summary><h3>1727. Largest Submatrix With Rearrangements 🌟 POTD</h3></summary>

`Medium` `Time Beats: 23.40%` `Memory Beats: 16.49%` `Commit:95bb94c` `Solved At: 2026-03-17 09:15:02` <code><a href="https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int area = 0;
        vector<int> prevRow(col, 0);

        for (int i = 0; i < row; i++) {
            vector<int> currRow = matrix[i];

            for (int j = 0; j < col; j++) {
                if (currRow[j] == 1) {
                    currRow[j] += prevRow[j];
                }
            }

            vector<int> heights = currRow;

            sort(heights.begin(), heights.end(), greater<int>());

            for (int i = 0; i < heights.size(); i++) {
                int base = i + 1;
                int height = heights[i];
                area = max(area, base * height);
            }

            prevRow = currRow;
        }
        return area;
    }
};
```

</details>


<details>
<summary><h3>1878. Get Biggest Three Rhombus Sums in a Grid</h3></summary>

`Medium` `Time Beats: 33.79%` `Memory Beats: 13.10%` `Commit:a3a2dd9` `Solved At: 2026-03-16 14:18:13` <code><a href="https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> d1(n, vector<int>(m));
        vector<vector<int>> d2(n, vector<int>(m));

        // build diagonal prefix sums
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d1[i][j] = grid[i][j];
                if (i > 0 && j > 0)
                    d1[i][j] += d1[i - 1][j - 1];

                d2[i][j] = grid[i][j];
                if (i > 0 && j + 1 < m)
                    d2[i][j] += d2[i - 1][j + 1];
            }
        }

        set<int> best;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                best.insert(grid[i][j]);

                for (int k = 1;; k++) {

                    int top = i - k;
                    int bottom = i + k;
                    int left = j - k;
                    int right = j + k;

                    if (top < 0 || bottom >= n || left < 0 || right >= m)
                        break;

                    int sum = 0;

                    // top -> right (D1)
                    sum += d1[i][right];
                    if (top - 1 >= 0 && j - 1 >= 0)
                        sum -= d1[top - 1][j - 1];

                    // right -> bottom (D2)
                    sum += d2[bottom][j];
                    if (i - 1 >= 0 && right + 1 < m)
                        sum -= d2[i - 1][right + 1];

                    // bottom -> left (D1)
                    sum += d1[bottom][j];
                    if (i - 1 >= 0 && left - 1 >= 0)
                        sum -= d1[i - 1][left - 1];

                    // left -> top (D2)
                    sum += d2[i][left];
                    if (top - 1 >= 0 && j + 1 < m)
                        sum -= d2[top - 1][j + 1];

                    // subtract corners counted twice
                    sum -= grid[top][j];
                    sum -= grid[i][right];
                    sum -= grid[bottom][j];
                    sum -= grid[i][left];

                    best.insert(sum);
                    if (best.size() < 3) {
                        best.insert(sum);
                    } else if (sum > *best.begin()) {
                        best.insert(sum);
                        best.erase(best.begin());
                    }
                }
            }
        }
        vector<int> ans;
        int cnt = 0;
        for (auto it = best.rbegin(); it != best.rend() && cnt < 3;
             ++it, ++cnt) {
            ans.push_back(*it);
        }
        return ans;
    }
};
```

</details>


<details>
<summary><h3>541. Reverse String II</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 10.17%` `Commit:3cba370` `Solved At: 2026-03-14 14:43:56` <code><a href="https://leetcode.com/problems/reverse-string-ii/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int L = 0;
        int R = min(L + k - 1, n - 1);
        int pos = 2 * k;

        while (L < n) {
            while (L < R) {
                swap(s[L], s[R]);
                L++;
                R--;
            }
            L = pos;
            R = min(L + k - 1, n - 1);
            pos += 2 * k;
        }
        return s;
    }
};
```

</details>


<details>
<summary><h3>344. Reverse String</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 97.74%` `Commit:02ccf38` `Solved At: 2026-03-14 13:54:47` <code><a href="https://leetcode.com/problems/reverse-string/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int L=0;
        int R=s.size()-1;
        while(L<R){
            swap(s[L],s[R]);
            L++;
            R--;
        }
    }
};
```

</details>


<details>
<summary><h3>1108. Defanging an IP Address</h3></summary>

`Easy` `Time Beats: 56.13%` `Memory Beats: 75.28%` `Commit:4433f57` `Solved At: 2026-03-14 13:51:57` <code><a href="https://leetcode.com/problems/defanging-an-ip-address/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;

        for (char c : address) {
            if (c == '.') {
                ans += "[.]";
            } else {
                ans += c;
            }
        }

        return ans;
    }
};
```

</details>


<details>
<summary><h3>1078. Occurrences After Bigram</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 81.82%` `Commit:31e9298` `Solved At: 2026-03-14 13:41:26` <code><a href="https://leetcode.com/problems/occurrences-after-bigram/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        vector<string> words;
        istringstream iss(text);
        string word;

        while (iss >> word) {
            words.push_back(word);
        }
        for (int i = 0; i < words.size() - 2; i++) {
            if (words[i] == first && words[i + 1] == second) {
                ans.push_back(words[i + 2]);
            }
        }
        return ans;
    }
};
```

</details>


<details>
<summary><h3>1415. The k-th Lexicographical String of All Happy Strings of Length n 🌟 POTD</h3></summary>

`Medium` `Time Beats: 100.00%` `Memory Beats: 89.21%` `Commit:bc49125` `Solved At: 2026-03-14 13:20:04` <code><a href="https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    void solve(int n, string& curr, int& count, int k, string& result) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                result = curr;
            }
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch) {
                continue;
            }

            curr.push_back(ch);

            solve(n, curr, count, k, result);

            if (!result.empty())
                return;
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int count = 0;

        solve(n, curr, count, k, result);

        return result;
    }
};
```

</details>


<details>
<summary><h3>69. Sqrt(x)</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 13.89%` `Commit:42f91c3` `Solved At: 2026-03-13 10:26:17` <code><a href="https://leetcode.com/problems/sqrtx/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int L = 1;
        int R = x;
        int ans = 0;

        while (L <= R) {
            int mid = L + (R - L) / 2;
            long long midSq = (long long)mid * mid;

            if (midSq == x) {
                return mid;
            } else if (midSq < x) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        return ans;
    }
};
```

</details>


<details>
<summary><h3>3296. Minimum Number of Seconds to Make Mountain Height Zero</h3></summary>

`Medium` `Time Beats: 76.77%` `Memory Beats: 90.32%` `Commit:cf76260` `Solved At: 2026-03-13 10:15:28` <code><a href="https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(workerTimes.begin(), workerTimes.end());

        long long L = 1;
        long long R = (long long)maxTime * mountainHeight * (mountainHeight + 1) / 2;
        long long result = R;

        while (L <= R) {
            long long mid = L + (R - L) / 2;
            long long height = 0;

            for (int t : workerTimes) {
                long long h = (sqrt(2.0 * (mid / t) + 0.25)) - 0.5 ;
                height += h;

                if (height >= mountainHeight)
                    break;
            }

            if (height >= mountainHeight) {
                result = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }

        return result;
    }
};
```

</details>


<details>
<summary><h3>1009. Complement of Base 10 Integer 🌟 POTD</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 4.02%` `Commit:423044b` `Solved At: 2026-03-11 13:19:50` <code><a href="https://leetcode.com/problems/complement-of-base-10-integer/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 0;
        }
        // no of bits required for the binary representation
        // for 5 its 3 bits (101)
        int bits = log2(n) + 1;

        // this is our mask for the XOR operation
        // mask is calculated by shifting 1 to left by no of bits 
        // and subtracting 1 from it 
        // for 5 it is 1<<3 = 1000 (decimal 8)
        //  8 - 1 = 7 (binay 111) 
        
        // 00000000 00000000 00000000 00000101 = 5 
        // 00000000 00000000 00000000 00000111 = mask for 5 
        // 00000000 00000000 00000000 00000010 = XOR (int^mask)

        int mask = (1 << bits) - 1;
        return n ^ mask;
    }
};
```

</details>


<details>
<summary><h3>3130. Find All Possible Stable Binary Arrays II 🌟 POTD</h3></summary>

`Hard` `Time Beats: 12.33%` `Memory Beats: 12.33%` `Commit:e2dd543` `Solved At: 2026-03-10 09:04:59` <code><a href="https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<vector<int>>> t;

    int solve(int i, int j, int last, int limit) {

        // Base: no elements
        if (i == 0 && j == 0)
            return 0;

        // Base: only zeros left
        if (j == 0) {
            if (last == 1)
                return 0;
            return (i <= limit) ? 1 : 0;
        }

        // Base: only ones left
        if (i == 0) {
            if (last == 0)
                return 0;
            return (j <= limit) ? 1 : 0;
        }

        if (t[i][j][last] != -1)
            return t[i][j][last];

        int result = 0;

        if (last == 0) {
            result =
                (solve(i - 1, j, 0, limit) + solve(i - 1, j, 1, limit)) % M;

            if (i - 1 >= limit)
                result = (result - solve(i - 1 - limit, j, 1, limit) + M) % M;

        } else {
            result =
                (solve(i, j - 1, 0, limit) + solve(i, j - 1, 1, limit)) % M;

            if (j - 1 >= limit)
                result = (result - solve(i, j - 1 - limit, 0, limit) + M) % M;
        }

        return t[i][j][last] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        t.assign(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));

        return (solve(zero, one, 0, limit) + solve(zero, one, 1, limit)) % M;
    }
};
```

</details>


<details>
<summary><h3>3129. Find All Possible Stable Binary Arrays I</h3></summary>

`Medium` `Time Beats: 65.04%` `Memory Beats: 84.55%` `Commit:566efaa` `Solved At: 2026-03-09 18:28:09` <code><a href="https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit) {
        if(onesLeft == 0 && zerosLeft == 0) {
            return 1;
        }

        if(t[onesLeft][zerosLeft][lastWasOne] != -1) {
            return t[onesLeft][zerosLeft][lastWasOne];
        }


        int result = 0;

        if(lastWasOne == true) { //explore 0s
            for(int len = 1; len <= min(zerosLeft, limit); len++) {
                result = (result + solve(onesLeft, zerosLeft - len, false, limit)) % M;
            }
        } else { //explore 1s
            for(int len = 1; len <= min(onesLeft, limit); len++) {
                result = (result + solve(onesLeft - len, zerosLeft, true, limit)) % M;
            }
        }

        return t[onesLeft][zerosLeft][lastWasOne] = result;

    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        int startWithOne = solve(one, zero, false, limit);
        int startWithZero = solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % M;

    }
};
```

</details>


<details>
<summary><h3>1980. Find Unique Binary String 🌟 POTD</h3></summary>

`Medium` `Time Beats: 100.00%` `Memory Beats: 86.66%` `Commit:9250095` `Solved At: 2026-03-08 14:40:17` <code><a href="https://leetcode.com/problems/find-unique-binary-string/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        
        for (int i = 0; i < n; i++) {
            char ch = (nums[i][i] == '0' ? '1' : '0');
            ans.push_back(ch);
        }
        
        return ans;
    }
};
```

</details>


<details>
<summary><h3>1888. Minimum Number of Flips to Make the Binary String Alternating 🌟 POTD</h3></summary>

`Medium` `Time Beats: 78.80%` `Memory Beats: 93.60%` `Commit:4773fc8` `Solved At: 2026-03-07 10:53:33` <code><a href="https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        // not using the extra s+s string and rotating using modulo %
        // not using extra space for the pattern strings 010101... 101010...
        // we know that cahracters are alternating so we can predict them by
        // index even 0 odd 1 for S1 even 1 ood 0 for S2

        int result = n;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0, j = 0;

        while (j < 2 * n) {
            char expectedS1 = (j % 2 ? '0' : '1');
            char expectedS2 = (j % 2 ? '1' : '0');

            if (s[j % n] != expectedS1)
                flip1++;
            if (s[j % n] != expectedS2)
                flip2++;

            if (j - i + 1 > n) {
                expectedS1 = (i % 2 ? '0' : '1');
                expectedS2 = (i % 2 ? '1' : '0');
                if (s[i % n] != expectedS1)
                    flip1--;
                if (s[i % n] != expectedS2)
                    flip2--;
                i++;
            }

            if (j - i + 1 == n) {
                result = min(result, min(flip1, flip2));
            }

            j++;
        }

        return result;
    }
};
```

</details>


<details>
<summary><h3>1784. Check if Binary String Has at Most One Segment of Ones 🌟 POTD</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 77.26%` `Commit:1a640bf` `Solved At: 2026-03-06 09:17:21` <code><a href="https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();

        // we have to check if the 01 appears or not
        // 10000 true no (01)
        // 111000 true no (01)
        // 10001 false (01) exists
        // 110011 false (01) exists

        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && s[i + 1] == '1') {
                return false;
            }
        }
        return true;
    }
};
```

</details>


<details>
<summary><h3>1758. Minimum Changes To Make Alternating Binary String</h3></summary>

`Easy` `Time Beats: 4.15%` `Memory Beats: 12.01%` `Commit:0b3d366` `Solved At: 2026-03-05 08:44:03` <code><a href="https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int minOperations(string s) {
        string copy0 = s;
        string copy1 = s;

        int n = s.length();

        int cnt = 0;
        int cnt0 = 1;
        int cnt1 = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                continue;
            }
            if (s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
            cnt++;
        }
        copy0[0] = '0';
        for (int i = 1; i < n; i++) {
            if (copy0[i] != copy0[i - 1]) {
                continue;
            }
            if (copy0[i] == '0') {
                copy0[i] = '1';
            } else {
                copy0[i] = '0';
            }
            cnt0++;
        }
        copy1[0] = '1';
        for (int i = 1; i < n; i++) {
            if (copy1[i] != copy1[i - 1]) {
                continue;
            }
            if (copy1[i] == '0') {
                copy1[i] = '1';
            } else {
                copy1[i] = '0';
            }
            cnt1++;
        }
        return min(cnt, min(cnt0, cnt1));
    }
};
```

</details>


<details>
<summary><h3>1582. Special Positions in a Binary Matrix 🌟 POTD</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 20.57%` `Commit:7cec811` `Solved At: 2026-03-04 10:44:24` <code><a href="https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

</details>


<details>
<summary><h3>1545. Find Kth Bit in Nth Binary String 🌟 POTD</h3></summary>

`Medium` `Time Beats: 40.02%` `Memory Beats: 22.63%` `Commit:9a420d6` `Solved At: 2026-03-03 17:41:05` <code><a href="https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    string invert(string s) {
        for (char& c : s) {
            c = (c == '0' ? '1' : '0');
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 2; i <= n; i++) {
            string prev = s;
            string sub = invert(prev);
            reverse(sub.begin(), sub.end());
            s = prev + "1" + sub;
        }

        return s[k-1];
    }
};
```

</details>


<details>
<summary><h3>1536. Minimum Swaps to Arrange a Binary Grid</h3></summary>

`Medium` `Time Beats: 100.00%` `Memory Beats: 65.85%` `Commit:4e805c7` `Solved At: 2026-03-02 09:51:28` <code><a href="https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n, 0);

        //count no of trailing zeros (zeros from the end) in each row
        for (int i = 0; i < n; i++) {
            int j = n - 1;
            int count = 0;
            while (j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }
            zeros[i] = count;
        }

        int ans = 0;
        //check if the current need is satisfied or not
        // if yes then move to next row
        // if no then go to the element where need is satisfied
        // swap the elements after the need is done
       
        // if need not satisfied in the zeros array retrun -1

        for (int i = 0; i < n; i++) {
            // need = n - row - 1 (no of zeros needed)
            int need = n - i - 1;
            int j = i;

            //check if the current need is satisfied or not
            // if yes then move to next row
            // if no then go to the element where need is satisfied
            
            while (j < n && zeros[j] < need) {
                j++;
            }

            // if need not satisfied in the zeros array retrun -1
            if (j == n) {
                return -1;
            }

            //count no of swaps
            ans += j - i;

            // swap the elements after the need is done
            // bubble swap mechanism
            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                j--;
            }
        }
        return ans;
    }
};
```

</details>


<details>
<summary><h3>1689. Partitioning Into Minimum Number Of Deci-Binary Numbers 🌟 POTD</h3></summary>

`Medium` `Time Beats: 100.00%` `Memory Beats: 53.96%` `Commit:d3a10da` `Solved At: 2026-03-01 11:33:26` <code><a href="https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int minPartitions(string n) {
        char c = '0';
        for (int i = 0; i < n.length(); i++) {
            if (n[i] > c) {
                c = n[i];
            }
        }
        return c - '0';
    }
};
```

</details>


<details>
<summary><h3>387. First Unique Character in a String</h3></summary>

`Easy` `Time Beats: 37.52%` `Memory Beats: 20.66%` `Commit:ad26e7e` `Solved At: 2026-03-01 11:18:27` <code><a href="https://leetcode.com/problems/first-unique-character-in-a-string/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
```

</details>


<details>
<summary><h3>1680. Concatenation of Consecutive Binary Numbers</h3></summary>

`Medium` `Time Beats: 59.06%` `Memory Beats: 17.45%` `Commit:4a56bc6` `Solved At: 2026-02-28 16:05:48` <code><a href="https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
        int M = 1e9 + 7;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int bits = log2(i) + 1;
            ans = ((ans << bits) % M + i) % M;
        }
        return ans;
    }
};
```

</details>


<details>
<summary><h3>3666. Minimum Operations to Equalize Binary String 🌟 POTD</h3></summary>

`Hard` `Time Beats: 52.31%` `Memory Beats: 32.31%` `Commit:3a50597` `Solved At: 2026-02-27 10:06:43` <code><a href="https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        vector<int> operations(n + 1, -1);
        queue<int> que;
        int startZeros = 0;

        for (char& ch : s) {
            if (ch == '0') {
                startZeros++;
            }
        }

        if (startZeros == 0) {
            return 0;
        }

        set<int> evenSet;
        set<int> oddSet;

        for (int cnt = 0; cnt <= n; cnt++) {
            if (cnt % 2 == 0) {
                evenSet.insert(cnt);
            } else {
                oddSet.insert(cnt);
            }
        }
        que.push(startZeros);
        operations[startZeros] = 0;
        if (startZeros % 2 == 0) {
            evenSet.erase(startZeros);
        } else {
            oddSet.erase(startZeros);
        }
        while (!que.empty()) {
            int z = que.front();
            que.pop();

            int min_newZ = z + k - 2 * min(k, z);
            int max_newZ = z + k - 2 * max(0, k - n + z);

            set<int>& currSet = (min_newZ % 2 == 0) ? evenSet : oddSet;
            auto it = currSet.lower_bound(min_newZ);

            while (it != currSet.end() && *it <= max_newZ) {
                int newZ = *it;

                if (operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;
                    if (newZ == 0) {
                        return operations[newZ];
                    }
                    que.push(newZ);
                }
                it = currSet.erase(it);
            }
        }
        return -1;
    }
};
```

</details>


<details>
<summary><h3>1404. Number of Steps to Reduce a Number in Binary Representation to One 🌟 POTD</h3></summary>

`Medium` `Time Beats: 100.00%` `Memory Beats: 24.61%` `Commit:3fd14f1` `Solved At: 2026-02-26 10:56:29` <code><a href="https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int numSteps(string s) {
        int count = 0;

        while (s != "1") {
            if (s.back() == '0') {
                // even divide by 2
                s.pop_back();
            } else {
                // odd add 1
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }

                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s = '1' + s; 
                }
            }
            count++;
        }

        return count;
    }
};
```

</details>

<details>
<summary><h3>1356. Sort Integers by The Number of 1 Bits 🌟 POTD</h3></summary>

`Easy` `Time Beats: 57.35%` `Memory Beats: 5.10%` `Commit:806525f` `Solved At: 2026-02-25 11:47:19` <code><a href="https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        function<bool(int,int)> comp = [](int a, int b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            if (countA == countB)
                return a < b;
            return countA < countB;
        };
        sort(arr.begin(), arr.end(),comp);
        return arr;
    }
};
```

</details>

<details>
<summary><h3>1356. Sort Integers by The Number of 1 Bits 🌟 POTD</h3></summary>

`Easy` `Time Beats: 23.28%` `Memory Beats: 5.10%` `Commit:ae9db26` `Solved At: 2026-02-25 11:36:56` <code><a href="https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>>vec;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            int ones=__builtin_popcount(arr[i]);
            vec.push_back({ones,arr[i]});
        }
        sort(vec.begin(),vec.end());
        for(auto i:vec){
            ans.push_back(i[1]);
        }
        return ans;
    }
};
```

</details>

<details>
<summary><h3>8. String to Integer (atoi)</h3></summary>

`Medium` `Time Beats: 100.00%` `Memory Beats: 97.58%` `Commit:523ef37` `Solved At: 2026-02-24 18:28:20` <code><a href="https://leetcode.com/problems/string-to-integer-atoi/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        while (i < n && s[i] == ' ') {
            i++;
        }

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        
        long result = 0;
        
        while (i < n && s[i]>=48 && s[i]<=57) {
            result = result * 10 + (s[i] - 48);
            
            if (sign * result > INT_MAX)
                return INT_MAX;
            if (sign * result < INT_MIN)
                return INT_MIN;
            
            i++;
        }
        
        return sign * result;
    }
};
```

</details>

<details>
<summary><h3>3. Longest Substring Without Repeating Characters</h3></summary>

`Medium` `Time Beats: 37.40%` `Memory Beats: 21.15%` `Commit:c4f1af8` `Solved At: 2026-02-24 16:22:20` <code><a href="https://leetcode.com/problems/longest-substring-without-repeating-characters/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n=s.length();
        int i=0;
        int j=0;
        int len=0;
        while (j<n){
            if(!st.count(s[j])){
                st.insert(s[j]);
                len=max(len,j-i+1);
                j++;
                continue;
            }
            st.erase(s[i]);
            i++;
        }
        return len;
    }
};
```

</details>

<details>
<summary><h3>1022. Sum of Root To Leaf Binary Numbers 🌟 POTD</h3></summary>

`Easy` `Time Beats: 9.54%` `Memory Beats: 19.46%` `Commit:026c9ac` `Solved At: 2026-02-24 15:42:26` <code><a href="https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int preOrder(TreeNode* node, string str) {
        if (!node) return 0;

        str.push_back(node->val + '0');

        if (!node->left && !node->right) {
            return stoi(str, nullptr, 2);
        }

        return preOrder(node->left, str) + 
               preOrder(node->right, str);
    }

    int sumRootToLeaf(TreeNode* root) {
        return preOrder(root, "");
    }
};
```

</details>

<details>
<summary><h3>1461. Check If a String Contains All Binary Codes of Size K 🌟 POTD</h3></summary>

`Medium` `Time Beats: 59.96%` `Memory Beats: 39.67%` `Commit:4edc9ea` `Solved At: 2026-02-23 21:27:03` <code><a href="https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string> st;
        for (int i = k; i <= n; i++) {
            st.insert(s.substr(i - k, k));
        }
        if (st.size() == pow(2, k)) {
            return true;
        }
        return false;
    }
};
```

</details>

<details>
<summary><h3>3713. Longest Balanced Substring I</h3></summary>

`Medium` `Time Beats: 41.45%` `Memory Beats: 59.78%` `Commit:8a82b83` `Solved At: 2026-02-22 23:43:31` <code><a href="https://leetcode.com/problems/longest-balanced-substring-i/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:

    bool checkBalanced(vector<int>& freq) {
        int common = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(common == 0)
                common = freq[i];
            else if(freq[i] != common) {
                return false;
            }
        }

        return true;
    }

    int longestBalanced(string s) {
        int n = s.length();

        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                //i..j
                if(checkBalanced(freq)) {
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }

        return maxLen;
    }
};
```

</details>

<details>
<summary><h3>190. Reverse Bits</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 11.17%` `Commit:fb11fc8` `Solved At: 2026-02-22 23:21:45` <code><a href="https://leetcode.com/problems/reverse-bits/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int reverseBits(int n) {
        // int to binary conversion
        bitset<32> binary_representation(n);
        // binary to string
        string binary_string = binary_representation.to_string();

        int i=0;
        int j=binary_string.size()-1;

        // reversing the string
        while(i<j){
            swap(binary_string[i],binary_string[j]);
            i++;
            j--;
        }

        // converting the string back to int
        return stoi(binary_string, nullptr, 2);
    }
};
```

</details>

<details>
<summary><h3>3640. Trionic Array II</h3></summary>

`Hard` `Time Beats: 100.00%` `Memory Beats: 76.29%` `Commit:c13b9cc` `Solved At: 2026-02-22 23:15:36` <code><a href="https://leetcode.com/problems/trionic-array-ii/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            int j = i;
            int p, q, k;
            long long res = 0;
            long long sum = 0, max_sum = 0;

            // First increasing phase
            while (j + 1 < n && nums[j] < nums[j + 1]) {
                j++;
            }
            p = j;
            if (p == i) continue;

            // Add peak and previous
            res += nums[p] + nums[p - 1];

            // Decreasing phase
            while (j + 1 < n && nums[j] > nums[j + 1]) {
                j++;
                res += nums[j];
            }
            q = j;

            // Validate third phase existence
            if (q == p || q + 1 >= n || nums[q] >= nums[q + 1]) {
                i = q;
                continue;
            }

            // Start final increasing phase
            res += nums[q + 1];

            // Extend final increasing (right side)
            sum = 0;
            max_sum = 0;
            k = q + 2;
            while (k < n && nums[k] > nums[k - 1]) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
                k++;
            }
            res += max_sum;

            // Extend first increasing backwards (left side)
            sum = 0;
            max_sum = 0;
            k = p - 2;
            while (k >= i) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
                k--;
            }
            res += max_sum;
            ans = max(ans, res);

            // Skip processed region
            i = q - 1;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><h3>3379. Transformed Array</h3></summary>

`Easy` `Time Beats: 80.84%` `Memory Beats: 10.17%` `Commit:fd9f9e1` `Solved At: 2026-02-22 23:14:00` <code><a href="https://leetcode.com/problems/transformed-array/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            int j = i + nums[i];

            while (j < 0) {
                j += n;
            }
            while (j >= n) {
                j -= n;
            }

            result.push_back(nums[j]);
        }

        return result;
    }
};
```

</details>

<details>
<summary><h3>868. Binary Gap 🌟 POTD</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 25.49%` `Commit:029cc44` `Solved At: 2026-02-22 19:14:50` <code><a href="https://leetcode.com/problems/binary-gap/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int binaryGap(int n) {
        // conversion of int to 32 bit binary representation string
        string s = bitset<32>(n).to_string();
        int i = 0;
        int j = 0;
        int result = INT_MIN;

        while (j < s.length()) {
            if (s[j] == '1') {
                // check for the first '1'
                if (i == 0) {
                    i = j;
                }
                result = max(result, j - i);
                i = j;
                j++;
                continue;
            }
            j++;
        }
        return result;
    }
};
```

</details>

<details>
<summary><h3>1. Two Sum</h3></summary>

`Easy` `Time Beats: 73.15%` `Memory Beats: 9.88%` `Commit:5f11611` `Solved At: 2026-02-21 22:24:52` <code><a href="https://leetcode.com/problems/two-sum/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for (int i=0;i<nums.size();i++){
            int a = nums[i];
            int diff = target -a;
            if(mpp.find(diff)!=mpp.end()){
                return {mpp[diff],i};
            }
            mpp[a]=i;
        }
        return {};
        
    }
};
```

</details>

<details>
<summary><h3>414. Third Maximum Number</h3></summary>

`Easy` `Time Beats: 100.00%` `Memory Beats: 92.66%` `Commit:049c8c6` `Solved At: 2026-02-21 22:15:11` <code><a href="https://leetcode.com/problems/third-maximum-number/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            //skipping the duplicates
            if (nums[i] == first || nums[i] == second || nums[i] == third) {
                continue;
            }

            if (nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];

            } else if (nums[i] > second) {
                third = second;
                second = nums[i];

            } else if (nums[i] > third) {
                third = nums[i];
            }
        }

        if (third == LLONG_MIN) {
            return first;
        }

        return third;
    }
};
```

</details>

<details>
<summary><h3>503. Next Greater Element II</h3></summary>

`Medium` `Time Beats: 5.59%` `Memory Beats: 98.76%` `Commit:1450318` `Solved At: 2026-02-21 21:16:29` <code><a href="https://leetcode.com/problems/next-greater-element-ii/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < 2*n) {
                if (nums[j % n] >= nums[i] + 1) {
                    result[i] = nums[j % n];
                    break;
                }
                j++;
            }
        }
        return result;
    }
};
```

</details>

<details>
<summary><h3>762. Prime Number of Set Bits in Binary Representation 🌟 POTD</h3></summary>

`Easy` `Time Beats: 72.17%` `Memory Beats: 7.90%` `Commit:3a9deb9` `Solved At: 2026-02-21 21:12:51` <code><a href="https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/" target="_blank">LINK</a></code>

```cpp
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

        int result = 0;
        for (int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);
            if (primes.count(setBits)) {
                result++;
            }
        }
        return result;
    }
};
```

</details>
