class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int orVal = 0, l = 0, maxLen = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++) {
            while((orVal & nums[i]) != 0) {
                orVal ^= nums[l];
                l++;
            }
            orVal |= nums[i];

            maxLen = max(maxLen, i - l + 1);
        }
        return maxLen;
    }
};