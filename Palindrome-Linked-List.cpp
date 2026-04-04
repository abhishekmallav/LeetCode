1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    bool isPalindrome(ListNode* head) {
14        vector<int> fwd;
15        vector<int> rew;
16        ListNode* current = head;
17        while (current != nullptr) {
18            fwd.push_back(current->val);
19            rew.push_back(current->val);
20            current = current->next;
21        }
22
23        reverse(rew.begin(), rew.end());
24
25        int i = 0;
26        
27        while (i < fwd.size()) {
28            if (fwd[i] != rew[i]) {
29                return false;
30            }
31            i++;
32        }
33        return true;
34    }
35};