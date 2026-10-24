class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            int m = accounts[i].size();
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += accounts[i][j];
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};