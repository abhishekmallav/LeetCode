1class Solution {
2public:
3    int preOrder(TreeNode* node, string str) {
4        if (!node) return 0;
5
6        str.push_back(node->val + '0');
7
8        if (!node->left && !node->right) {
9            return stoi(str, nullptr, 2);
10        }
11
12        return preOrder(node->left, str) + 
13               preOrder(node->right, str);
14    }
15
16    int sumRootToLeaf(TreeNode* root) {
17        return preOrder(root, "");
18    }
19};