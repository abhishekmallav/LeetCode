1class Solution {
2public:
3    int reverseBits(int n) {
4        // int to binary conversion
5        bitset<32> binary_representation(n);
6        // binary to string
7        string binary_string = binary_representation.to_string();
8
9        int i=0;
10        int j=binary_string.size()-1;
11
12        // reversing the string
13        while(i<j){
14            swap(binary_string[i],binary_string[j]);
15            i++;
16            j--;
17        }
18
19        // converting the string back to int
20        return stoi(binary_string, nullptr, 2);
21    }
22};