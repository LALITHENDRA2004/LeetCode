class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> mp;
        for(int i : nums) mp[i]++;

        for(auto i : mp) {
            if(i.second % 2 != 0) return false;
        }
        return true;
    }
};