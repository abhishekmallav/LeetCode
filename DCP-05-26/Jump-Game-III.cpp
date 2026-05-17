1class Solution {
2public:
3    int n;
4
5    bool dfs(vector<int>& arr, int i) {
6        if(i < 0 || i >= n || arr[i] < 0) {
7            return false;
8        }
9        if(arr[i] == 0)
10            return true;
11
12        arr[i] *= -1;
13        int left  = dfs(arr, i - arr[i]);
14        int right = dfs(arr, i + arr[i]);
15        return left || right;
16    }
17
18    bool canReach(vector<int>& arr, int start) {
19        n = arr.size();
20        return dfs(arr, start);
21    }
22};