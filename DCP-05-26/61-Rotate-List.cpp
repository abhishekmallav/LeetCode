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
11
12class Solution {
13public:
14    int size(ListNode* head) {
15        int n = 0;
16        while (head != NULL) {
17            n++;
18            head = head->next;
19        }
20        return n;
21    }
22
23    ListNode* rotateRight(ListNode* head, int k) {
24        if (head == NULL)
25            return head;
26
27        int n = size(head);
28        int loop = k % n;
29        loop = n - loop;
30
31        if (n == 1 || loop == n)
32            return head;
33
34        int j = 0;
35        ListNode* temp = head;
36        ListNode* firstAddress = head;
37
38        while (temp != NULL) {
39            j++;
40            if (j == loop) {
41                firstAddress = temp->next;
42                temp->next = NULL;
43                break;
44            }
45            temp = temp->next;
46        }
47
48        temp = firstAddress;
49        while (temp->next != NULL) {
50            temp = temp->next;
51        }
52
53        temp->next = head;
54        return firstAddress;
55    }
56};
57