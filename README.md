# LeetCode Solutions

A daily log of my LeetCode solutions, automatically updated on every submission.

<a href="https://leetcode.com/u/abhishekmallav/" target="_blank"><img src="https://img.shields.io/badge/LeetCode-abhishekmallav-FFA116?style=flat&logo=leetcode&logoColor=white" alt="LeetCode Profile"/></a>

---

<!-- SUBMISSIONS -->

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
