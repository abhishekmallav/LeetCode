class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int max_val = -1;
        int n = nums.size();
        vector<int> prefixGCD(n);

        for (int i = 0; i < n; i++) {
            max_val = max(nums[i], max_val);
            prefixGCD[i] = gcd(nums[i], max_val);
        }

        long long ans = 0;
        sort(prefixGCD.begin(), prefixGCD.end());

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            ans += gcd(prefixGCD[i], prefixGCD[j]);
        }

        return ans;
    }

private:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};
