class Solution {
public:
    int next(vector<int> &nums, int ele, int ind) {
        ind++;
        while(ind < nums.size() && nums[ind] == ele) ind++;
        return ind >= nums.size() ? -1 : nums[ind];
    }

    int prev(vector<int> &nums, int ele, int ind) {
        ind--;
        while(ind >= 0 && nums[ind] == ele) ind--;
        return ind < 0 ? -1 : nums[ind];
    }
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        for(int i = 1 ; i < nums.size() - 1 ; i++) {
            int nxt = next(nums, nums[i], i);
            int prv = prev(nums, nums[i], i);

            if(nums[i] == nums[i + 1] || nxt == -1 || prv == -1) continue;
            if((nxt < nums[i] && prv < nums[i]) || (nxt > nums[i] && prv > nums[i])) {
                ans++;
            }
        }
        return ans;
    }
};