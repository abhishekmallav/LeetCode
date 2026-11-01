1class Solution {
2public:
3    vector<int> sortByBits(vector<int>& arr) {
4        function<bool(int,int)> comp = [](int a, int b) {
5            int countA = __builtin_popcount(a);
6            int countB = __builtin_popcount(b);
7            if (countA == countB)
8                return a < b;
9            return countA < countB;
10        };
11        sort(arr.begin(), arr.end(),comp);
12        return arr;
13    }
14};