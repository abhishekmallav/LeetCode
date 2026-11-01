1class Solution {
2public:
3    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
4        int time = 0;
5        int n = timeSeries.size();
6        for(int i = 0;i<n;i++){
7            if (i<n-1 && timeSeries[i]+duration-1>=timeSeries[i+1]){
8                time+=(timeSeries[i+1]-timeSeries[i]);
9                continue;
10            }
11            time+=duration;
12        }
13        return time;
14    }
15};