class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxPro = 0, maxDif = 0, maxi = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            maxPro = max(maxPro, maxDif * (long long)nums[i]);
            maxDif = max(maxDif, maxi - (long long)nums[i]);
            maxi = max(maxi, (long long)nums[i]);
        }
        return maxPro;
    }
};