class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> cnt, curr;
        for(int i : nums) cnt[i]++;

        for(int i = 0 ; i < nums.size() ; i++) {
            curr[nums[i]]++;

            int left = i + 1, right = nums.size() - (i + 1);
            if(curr[nums[i]] * 2 > left && (cnt[nums[i]] - curr[nums[i]]) * 2 > right) {
                return i;
            }
        }
        return -1;
    }
};