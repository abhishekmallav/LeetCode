1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    bool hasCycle(ListNode* head) {
12        unordered_set<ListNode*> visited; 
13
14        ListNode* current = head;
15        while (current != nullptr) {
16            if (visited.find(current) != visited.end()) {
17                return true;
18            }
19            visited.insert(current);
20            current = current->next;
21        }
22        return false;
23    }
24};