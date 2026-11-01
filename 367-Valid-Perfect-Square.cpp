class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1)
            return false;
        if (num == 1)
            return true;

        long L = 1, R = num;

        while (L <= R) {
            long mid = L + (R - L) / 2;
            long square = mid * mid;

            if (square == num) {
                return true;
            } else if (square < num) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }

        return false;
    }
};