class Solution {
public:
    int find(int i, int tar, vector<int> &nums) {
        if(i == 0) {
            //if(nums[i] == 0) return 2;
            if(nums[i] == tar && nums[i] == 0) return 2;
            if(nums[i] == tar && nums[i] != 0) return 1;
            if(nums[i] == tar + 2 * nums[i]) return 1;
            return 0;
        }
        int add = find(i - 1, tar - nums[i], nums);
        int sub = find(i - 1, tar + nums[i], nums);
        return add + sub; 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return find(nums.size() - 1, target, nums);
    }
};