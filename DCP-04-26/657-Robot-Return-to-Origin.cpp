1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int x = 0;
5        int y = 0;
6
7        for(char &ch : moves) {
8            if(ch == 'U')       y++;
9            else if(ch == 'D')  y--;
10            else if(ch == 'L')  x--;
11            else if(ch == 'R')  x++;
12        }
13
14        return x == 0 && y == 0;
15    }
16};