class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        int cnt = 0;

        for (int i = 0; i < jewels.length(); i++) {
            st.insert(jewels[i]);
        }

        for (int i = 0; i < stones.length(); i++) {
            if (st.find(stones[i]) != st.end()) {
                cnt++;
            }
        }
        return cnt;
    }
};