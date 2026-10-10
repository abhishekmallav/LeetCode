class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int MAXD = 100000;
        vector<long long> freq(MAXD + 1, 0);
        int maxDiff = 0;
        long long totalDiff = 0;

        for (size_t i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            totalDiff += d;
            maxDiff = max(maxDiff, d);
        }

        long long k = (long long)k1 + k2;

        if (totalDiff <= k) return 0;

        for (int d = maxDiff; d > 0 && k > 0; d--) {
            long long moves = min(k, freq[d]);
            freq[d] -= moves;
            freq[d - 1] += moves;
            k -= moves;
        }

        long long ans = 0;
        for (int d = 1; d <= maxDiff; d++) ans += (long long)d * d * freq[d];
        return ans;
    }
};