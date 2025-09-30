class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp;
        int size = nums.size();
        while(size != 1) {
            for(int i = 0 ; i < size - 1 ; i++) {
                temp.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = temp;
            temp = {};
            size--;
        }
        return nums[0];
    }
};