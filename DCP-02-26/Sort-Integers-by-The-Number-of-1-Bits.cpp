1class Solution {
2public:
3    vector<int> sortByBits(vector<int>& arr) {
4        vector<vector<int>>vec;
5        vector<int>ans;
6        for(int i=0;i<arr.size();i++){
7            int ones=__builtin_popcount(arr[i]);
8            vec.push_back({ones,arr[i]});
9        }
10        sort(vec.begin(),vec.end());
11        for(auto i:vec){
12            ans.push_back(i[1]);
13        }
14        return ans;
15    }
16};