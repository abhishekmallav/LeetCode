class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey,
                     string ruleValue) {
        int Idx, cnt = 0;

        if (ruleKey == "type") {
            Idx = 0;
        } else if (ruleKey == "color") {
            Idx = 1;
        } else {
            Idx = 2;
        }

        for (int i = 0; i < items.size(); i++) {
            if (items[i][Idx] == ruleValue) {
                cnt++;
            }
        }
        return cnt;
    }
};