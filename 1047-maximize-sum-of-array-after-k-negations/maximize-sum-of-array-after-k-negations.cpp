class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int i = 0;
        int sum = 0;
        int prev = INT_MAX;
        while(i < n && k > 0 && nums[i] < 0) {
            sum += abs(nums[i]);
            prev = abs(nums[i]);
            i++;
            k--;
        }

        if(i == n) {
            if(k % 2 != 0) {
                sum -= 2 * abs(nums[i - 1]);
                return sum;
            }
        }

        if(k % 2 == 0 || nums[i] == 0) k = 0;
        else {
            if(prev < nums[i]) {
                sum -= 2 * prev;
            }
            else {
                sum -= nums[i];
                i++;
            }
        }

        while(i < n) sum += nums[i++];

        return sum;
    }
};