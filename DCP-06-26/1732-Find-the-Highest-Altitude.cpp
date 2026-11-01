class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxi = INT_MIN;
        int height = 0;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, height);
            height += gain[i];
        }
        return max(maxi, height);
    }
};