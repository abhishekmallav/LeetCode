
<details>
<summary><h3>762. Prime Number of Set Bits in Binary Representation</h3></summary>

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

