class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int hash[50000] = {0};
        int first[50000];
        int last[50000];
        
        // Initialize the first array with -1 to keep track of unvisited elements
        for(int i = 0; i < 50000; i++) {
            first[i] = -1;
        }

        int n = nums.size();
        int max_freq = 0;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            hash[val]++;
            
            if (first[val] == -1) {
                first[val] = i;
            }
            
            last[val] = i;

            if (hash[val] > max_freq) {
                max_freq = hash[val];
            }
        }

        int min_len = n;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            if (hash[val] == max_freq) {
                int len = last[val] - first[val] + 1;
                if (len < min_len) {
                    min_len = len;
                }
            }
        }

        return min_len;
    }
};
