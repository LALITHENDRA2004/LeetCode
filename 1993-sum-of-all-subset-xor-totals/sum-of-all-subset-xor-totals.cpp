class Solution {
public:
    int find(int i, int x, vector<int> &nums) {
        if(i == nums.size()) return x;
        int pick =  find(i + 1, x ^ nums[i], nums);
        int notPick = find(i + 1, x, nums);
        return pick + notPick;
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = find(0, 0, nums);
        return ans;
    }
};