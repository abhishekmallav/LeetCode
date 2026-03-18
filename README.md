# LeetCode Solutions

A daily log of my LeetCode solutions, automatically updated on every submission.

<a href="https://leetcode.com/u/abhishekmallav/" target="_blank"><img src="https://img.shields.io/badge/LeetCode-abhishekmallav-FFA116?style=flat&logo=leetcode&logoColor=white" alt="LeetCode Profile"/></a>

---

<!-- SUBMISSIONS -->

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
