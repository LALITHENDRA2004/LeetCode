class Solution {
public:
    int findLHS(vector<int>& nums) {
        // 1 2 2 2 3 3 4 7 
        sort(nums.begin(), nums.end());

        int maxi = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            int ind = upper_bound(nums.begin(), nums.end(), nums[i] + 1) - nums.begin() - 1;
            //cout << ind << " ";
            if(nums[ind] == nums[i] + 1) maxi = max(maxi, ind - i + 1);
        }
        return maxi;
    }
};