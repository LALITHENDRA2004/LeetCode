class Solution {
public:
    void find(int i, int x, int &sum, vector<int> &nums) {
        if(i == nums.size()) {
            sum += x;
            return;
        }
        x = x ^ nums[i];
        find(i + 1, x, sum, nums);
        x = x ^ nums[i];
        find(i + 1, x, sum, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        int x = 0, sum = 0;
        find(0, x, sum, nums);
        return sum;
    }
};