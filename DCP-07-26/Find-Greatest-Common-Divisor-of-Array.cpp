class Solution {
public:
    int gcd(int a, int b) {

        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int ele : nums) {
            maxi = max(maxi, ele);
            mini = min(mini, ele);
        }

        return gcd(maxi, mini);
    }
};