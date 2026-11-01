1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
10 * right(right) {}
11 * };
12 */
13class Solution {
14public:
15    void findPaths(TreeNode* root, string path, vector<string>& ans) {
16        if (!root) {
17            return;
18        }
19
20        path += to_string(root->val);
21
22        if (!root->left && !root->right) {
23            ans.push_back(path);
24            return;
25        }
26        path += "->";
27        findPaths(root->left, path, ans);
28        findPaths(root->right, path, ans);
29    }
30
31    vector<string> binaryTreePaths(TreeNode* root) {
32        vector<string> ans;
33        findPaths(root, "", ans);
34        return ans;
35    }
36};