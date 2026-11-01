class Solution {
public:
    long long sumAndMultiply(int n) {
        long long res = 0;
        long long sum = 0;
        int i = 1;
        while (n) {
            if (n % 10 != 0) {
                res = res + (n % 10) * i;
                sum += n % 10;
                i = i * 10;
            }
            n = n / 10;
        }
        return res * sum;
    }
};