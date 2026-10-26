class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        long long res = 0, curr = 0;

        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && coins[j][1] <= coins[i][0] + k - 1) {
                curr +=
                    (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            if (j < n && coins[j][0] <= coins[i][0] + k - 1) {
                long long part =
                    (long long)(coins[i][0] + k - 1 - coins[j][0] + 1) *
                    coins[j][2];
                res = max(res, curr + part);
            }
            curr -= (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }
        curr = 0;

        for (int i = 0, j = 0; i < n; i++) {
            curr += (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
            while (j < n && coins[j][1] < coins[i][1] - k + 1) {
                curr -=
                    (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            if (coins[j][0] < coins[i][1] - k + 1) {
                long long part =
                    (long long)(coins[i][1] - k + 1 - coins[j][0]) *
                    coins[j][2];
                res = max(res, curr - part);
            } else {
                res = max(res, curr);
            }
        }
        return res;
    }
};