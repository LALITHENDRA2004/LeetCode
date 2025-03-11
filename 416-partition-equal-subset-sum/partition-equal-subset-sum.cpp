class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum += i;

        if(sum % 2 != 0) return false;
        vector<int> prev((sum / 2) + 1, 0), curr((sum / 2) + 1, 0);

        prev[0] = true;
        if(nums[0] <= (sum / 2)) prev[nums[0]] = true;

        for(int i = 1 ; i < nums.size() ; i++) {
            curr[0] = true;
            for(int t = 1 ; t <= (sum / 2) ; t++) {
                bool pick = false;
                if(nums[i] <= t) pick = prev[t - nums[i]];
                bool notPick = prev[t];

                curr[t] = pick || notPick;
            }
            prev = curr;
        }

        return curr[(sum / 2)];
    }
};