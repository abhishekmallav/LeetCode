1class Solution {
2public:
3    int largestSubmatrix(vector<vector<int>>& matrix) {
4        int row = matrix.size();
5        int col = matrix[0].size();
6        int area = 0;
7        vector<int> prevRow(col, 0);
8
9        for (int i = 0; i < row; i++) {
10            vector<int> currRow = matrix[i];
11
12            for (int j = 0; j < col; j++) {
13                if (currRow[j] == 1) {
14                    currRow[j] += prevRow[j];
15                }
16            }
17
18            vector<int> heights = currRow;
19
20            sort(heights.begin(), heights.end(), greater<int>());
21
22            for (int i = 0; i < heights.size(); i++) {
23                int base = i + 1;
24                int height = heights[i];
25                area = max(area, base * height);
26            }
27
28            prevRow = currRow;
29        }
30        return area;
31    }
32};