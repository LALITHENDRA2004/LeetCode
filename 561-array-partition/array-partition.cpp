class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i += 2) {
            sum += arr[i];
        }
        return sum;
    }
};