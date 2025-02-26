class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        int maxi = prefix[0], mini = prefix[0], ind1 = 0, ind2 = 0;
        for(int i = 1 ; i < nums.size() ; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
            if(prefix[i] > maxi) {
                maxi = prefix[i];
                ind1 = i;
            }
            if(prefix[i] < mini) {
                mini = prefix[i];
                ind2 = i;
            }
        }

        int lpmForm1 = 0, lnmForm1 = 0, lpmForm2 = 0, lnmForm2 = 0;
        for(int i = 0 ; i <= max(ind1 - 1, ind2 - 1) ; i++) {
            if(i <= ind1 - 1) {
                lpmForm1 = max(lpmForm1, prefix[i]);
                lnmForm1 = min(lnmForm1, prefix[i]);
            }
            if(i <= ind2 - 1) {
                lpmForm2 = max(lpmForm2, prefix[i]);
                lnmForm2 = min(lnmForm2, prefix[i]);
            }
        }

        int ans1 = 0, ans2 = 0;
        if(maxi < 0) ans1 = abs(maxi - lpmForm1);
        else ans1 = maxi - lnmForm1;

        if(mini < 0) ans2 = abs(mini - lpmForm2);
        else ans2 = mini - lnmForm2;

        return max(ans1, ans2);

        
    }
};