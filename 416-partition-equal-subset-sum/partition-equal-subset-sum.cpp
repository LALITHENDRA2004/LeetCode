class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum += i;

        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(nums.size(), vector<int> ((sum / 2) + 1, 0));

        for(int i = 0 ; i < nums.size() ; i++) {
            dp[i][0] = true;
        }

        if(nums[0] <= (sum / 2)) dp[0][nums[0]] = true;

        for(int i = 1 ; i < nums.size() ; i++) {
            for(int t = 1 ; t <= (sum / 2) ; t++) {
                bool pick = false;
                if(nums[i] <= t) pick = dp[i - 1][t - nums[i]];
                bool notPick = dp[i - 1][t];

                dp[i][t] = pick || notPick;
            }
        }

        return dp[nums.size() - 1][(sum / 2)];
    }
};