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
11    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
12        unordered_set<ListNode*> visited; 
13
14        ListNode* current = headA;
15        while (current != nullptr) {
16            visited.insert(current);
17            current = current->next;
18        }
19
20        current = headB;
21        while (current != nullptr) {
22            if (visited.find(current) != visited.end()) {
23                return current;
24            }
25            current = current->next;
26        }
27        return nullptr;
28    }
29};