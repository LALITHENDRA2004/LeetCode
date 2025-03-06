class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cont = nums[0], mx = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) {
            cont = max(nums[i], cont + nums[i]);
            mx = max(cont, mx);
        }
        return mx;
    }
};