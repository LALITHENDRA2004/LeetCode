class Solution {
public:
    // 1 2 3 3 
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 1, mini = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] - mini > k) {
                cnt++;
                mini = nums[i];
            }
        }
        return cnt;
    }
};