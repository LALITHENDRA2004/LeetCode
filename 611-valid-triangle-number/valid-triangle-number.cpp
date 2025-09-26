class Solution {
public:
    int findIndexOfLargestNumberLessThanNum(int low, int high, int num, vector<int> &nums) {
        while(low <= high) {
            int mid = low + (high - low) / 2; 
            if(nums[mid] >= num) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return high;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() - 2 ; i++) {
            for(int j = i + 1 ; j < nums.size() - 1 ; j++) {
                int num = nums[i] + nums[j];
                if(num > nums[j + 1]) {
                    int ind = findIndexOfLargestNumberLessThanNum(j + 1, n - 1, num, nums);
                    // cout << ind << " ";
                    cnt += ind - j;
                }
            }
        }
        return cnt;
    }
};