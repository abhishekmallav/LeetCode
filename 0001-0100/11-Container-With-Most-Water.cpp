class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n == 1)
            return 0;

        int l = 0;
        int r = n - 1;
        int maxi = 0;

        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);

            maxi = max(maxi, area);
            
            if (height[r] > height[l]) {
                l++;
            } else {
                r--;
            }
        }
        return maxi;
    }
};