class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        arr2.push_back(INT_MAX);
        int count = 0;
        auto b = arr2.begin();

        for (int a : arr1) {
            while (*b < a - d) {
                b++;
            }
            count += *b > a + d;
        }
        return count;
    }
};