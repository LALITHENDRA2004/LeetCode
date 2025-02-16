class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        for(int i = 0 ; i < nums.size() ; i++) {
            int rem = target - nums[i];
            if(index.find(rem) != index.end()) {
                return {i, index[rem]};
            }
            else {
                index[nums[i]] = i;
            }
        }
        return {};
    }
};