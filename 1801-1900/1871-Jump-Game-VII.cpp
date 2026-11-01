class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int> arr(n + 1, 0);
        if (s[n - 1] == '1')
            return false;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += arr[i];
            if (i == 0 || s[i] == '0' && cnt > 0) {
                if (i + minJump < n)
                    arr[i + minJump] += 1;
                if (i + maxJump + 1 < n)
                    arr[i + maxJump + 1] -= 1;
            }
        }
        return cnt > 0;
    }
};