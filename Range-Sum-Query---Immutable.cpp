1class NumArray {
2private:
3    vector<int> data;
4
5public:
6    NumArray(vector<int>& nums) {
7        data.resize(nums.size()); 
8        int sum = 0;
9
10        for (int i = 0; i < nums.size(); i++) {
11            sum += nums[i];
12            data[i] = sum;
13        }
14    }
15
16    int sumRange(int left, int right) {
17        if (left == 0) {
18            return data[right];
19        }
20        return data[right] - data[left - 1];
21    }
22};
23
24/**
25 * Your NumArray object will be instantiated and called as such:
26 * NumArray* obj = new NumArray(nums);
27 * int param_1 = obj->sumRange(left,right);
28 */