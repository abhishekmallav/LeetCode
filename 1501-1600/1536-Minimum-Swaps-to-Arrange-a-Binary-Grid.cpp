1class Solution {
2public:
3    int minSwaps(vector<vector<int>>& grid) {
4        int n = grid.size();
5        vector<int> zeros(n, 0);
6
7        //count no of trailing zeros (zeros from the end) in each row
8        for (int i = 0; i < n; i++) {
9            int j = n - 1;
10            int count = 0;
11            while (j >= 0 && grid[i][j] == 0) {
12                count++;
13                j--;
14            }
15            zeros[i] = count;
16        }
17
18        int ans = 0;
19        //check if the current need is satisfied or not
20        // if yes then move to next row
21        // if no then go to the element where need is satisfied
22        // swap the elements after the need is done
23       
24        // if need not satisfied in the zeros array retrun -1
25
26        for (int i = 0; i < n; i++) {
27            // need = n - row - 1 (no of zeros needed)
28            int need = n - i - 1;
29            int j = i;
30
31            //check if the current need is satisfied or not
32            // if yes then move to next row
33            // if no then go to the element where need is satisfied
34            
35            while (j < n && zeros[j] < need) {
36                j++;
37            }
38
39            // if need not satisfied in the zeros array retrun -1
40            if (j == n) {
41                return -1;
42            }
43
44            //count no of swaps
45            ans += j - i;
46
47            // swap the elements after the need is done
48            // bubble swap mechanism
49            while (j > i) {
50                swap(zeros[j], zeros[j - 1]);
51                j--;
52            }
53        }
54        return ans;
55    }
56};