1class Solution {
2public:
3    TreeNode* BST(vector<int>& nums, int L, int R) {
4        if (L > R) {
5            return nullptr;
6        }
7        
8        int M = L + (R - L) / 2;
9        
10        TreeNode* root = new TreeNode(nums[M]);
11        
12        root->left = BST(nums, L, M - 1);
13        root->right = BST(nums, M + 1, R);
14        
15        return root;
16    }
17
18    TreeNode* sortedArrayToBST(vector<int>& nums) {
19        return BST(nums, 0, nums.size() - 1);
20    }
21};