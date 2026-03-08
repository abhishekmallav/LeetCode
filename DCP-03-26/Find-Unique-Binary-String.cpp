1class Solution {
2public:
3    string findDifferentBinaryString(vector<string>& nums) {
4        int n = nums.size();
5        string ans = "";
6        
7        for (int i = 0; i < n; i++) {
8            char ch = (nums[i][i] == '0' ? '1' : '0');
9            ans.push_back(ch);
10        }
11        
12        return ans;
13    }
14};