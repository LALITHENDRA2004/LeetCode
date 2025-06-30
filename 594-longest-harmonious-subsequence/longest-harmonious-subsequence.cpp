class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        int len = 0;
        for(int i : nums) mp[i]++;

        for(int i = 0 ; i < nums.size() ; i++) {
            if(mp.find(nums[i] + 1) != mp.end())
                len = max(len, mp[nums[i]] + mp[nums[i] + 1]);
        }
        
        return len;
    }
};