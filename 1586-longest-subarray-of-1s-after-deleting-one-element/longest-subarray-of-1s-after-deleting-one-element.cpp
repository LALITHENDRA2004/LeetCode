class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroes = 0, len = 0, maxLen = 0, j = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] == 1) len++; // 2 3 4 5 6 
            else {
                if(zeroes == 0) {
                    zeroes++; // 1
                    len++; // 1
                }
                else {
                    while(zeroes != 0) {
                        if(nums[j] == 0) zeroes--; // 0
                        j++; // 1
                        len--;
                    }
                    zeroes++; // 1
                    len++;
                }
            }

            maxLen = max(len, maxLen); // 4
        }

        return maxLen - 1;
    }
};