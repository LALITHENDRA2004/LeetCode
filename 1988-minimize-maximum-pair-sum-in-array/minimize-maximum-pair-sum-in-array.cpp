class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size() - 1, maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() / 2 ; i++) {
            maxi = max(maxi, nums[i] + nums[l - i]);
        }
        return maxi;
    }
};