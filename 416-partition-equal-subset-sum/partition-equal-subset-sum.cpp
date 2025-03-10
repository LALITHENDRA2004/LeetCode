class Solution {
public:
    bool find(int i, int tar, vector<int> &arr, vector<vector<int>> &dp) {
        if(tar == 0) return true;
        if(i == 0) {
            if(tar == arr[i]) return true;
            return false;
        }
        if(dp[i][tar] != -1) return dp[i][tar];
        int pick = 0;
        if(arr[i] <= tar) pick = find(i - 1, tar - arr[i], arr, dp);
        int notPick = find(i - 1, tar, arr, dp);
        return dp[i][tar] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum += i;

        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(nums.size(), vector<int> ((sum / 2) + 1, -1));
        return find(nums.size() - 1, sum / 2, nums, dp);
    }
};