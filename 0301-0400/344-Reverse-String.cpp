1class Solution {
2public:
3    void reverseString(vector<char>& s) {
4        int L=0;
5        int R=s.size()-1;
6        while(L<R){
7            swap(s[L],s[R]);
8            L++;
9            R--;
10        }
11    }
12};