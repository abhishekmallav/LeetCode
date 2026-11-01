1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_set<char>st;
5        int n=s.length();
6        int i=0;
7        int j=0;
8        int len=0;
9        while (j<n){
10            if(!st.count(s[j])){
11                st.insert(s[j]);
12                len=max(len,j-i+1);
13                j++;
14                continue;
15            }
16            st.erase(s[i]);
17            i++;
18        }
19        return len;
20    }
21};