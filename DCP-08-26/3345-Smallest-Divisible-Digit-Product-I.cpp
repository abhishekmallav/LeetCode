class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int tmp = n;
            int product = 1;

            while (tmp > 0) {
                product *= (tmp % 10);
                tmp /= 10;
            }

            if (product % t == 0) {
                return n;
            }

            n++;
        }
    }
};