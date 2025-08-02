class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 1;
        int maxi = nums[0];
        int maxLen = 1;
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] > maxi) {
                len = 1;
                maxLen = 1;
                maxi = nums[i];
            }
            else if(nums[i] == maxi) {
                if(nums[i - 1] == maxi) {
                    len++;
                }
                else {
                    len = 1;
                }
            }
            else {
                len = 1;
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};