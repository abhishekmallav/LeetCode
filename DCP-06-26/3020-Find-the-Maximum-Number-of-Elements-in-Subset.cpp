class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int maxLen = 1;

        // Handle the special case for 1
        if (count.find(1) != count.end()) {
            int ones = count[1];
            if (ones % 2 == 0) {
                ones--;
            }
            maxLen = max(maxLen, ones);
        }

        // Process other numbers
        for (auto const& [x, _] : count) {
            if (x == 1)
                continue;

            int currentLen = 0;
            long long curr = x;

            while (curr <= 1000000000LL && count.count((int)curr) &&
                   count[(int)curr] >= 2) {
                currentLen += 2;
                curr *= curr;
            }

            if (curr <= 1000000000LL && count.count((int)curr) &&
                count[(int)curr] > 0) {
                currentLen += 1;
            } else {
                currentLen -= 1;
            }

            maxLen = max(maxLen, currentLen);
        }

        return maxLen;
    }
};