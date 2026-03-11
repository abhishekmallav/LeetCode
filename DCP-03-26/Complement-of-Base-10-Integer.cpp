1class Solution {
2public:
3    int bitwiseComplement(int n) {
4        if (n == 0) {
5            return 1;
6        }
7        if (n == 1) {
8            return 0;
9        }
10        // no of bits required for the binary representation
11        // for 5 its 3 bits (101)
12        int bits = log2(n) + 1;
13
14        // this is our mask for the XOR operation
15        // mask is calculated by shifting 1 to left by no of bits 
16        // and subtracting 1 from it 
17        // for 5 it is 1<<3 = 1000 (decimal 8)
18        //  8 - 1 = 7 (binay 111) 
19        
20        // 00000000 00000000 00000000 00000101 = 5 
21        // 00000000 00000000 00000000 00000111 = mask for 5 
22        // 00000000 00000000 00000000 00000010 = XOR (int^mask)
23
24        int mask = (1 << bits) - 1;
25        return n ^ mask;
26    }
27};