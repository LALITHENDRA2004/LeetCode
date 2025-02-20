class Solution {
public:
    void find(string s, int &ind, string &ans, vector<string> &nums) {
        if(ans != "") return;
        if(s.size() == nums.size()) {
            if(ind < nums.size() && nums[ind] != s) {
                ans = s;
            }
            else ind++;
            return;
        }
        s += "0";
        find(s, ind, ans, nums);
        s.pop_back();
        s += "1";
        find(s, ind, ans, nums);
    } 
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(),nums.end());
        for(auto i : nums) cout << i << " ";
        int ind = 0;
        string s = "", ans = "";
        find(s, ind, ans, nums);
        if(ans == "") {
            ans = nums[nums.size() - 1];
            for(int i = nums.size() - 1 ; i >= 0 ; i--) {
                if(ans[i] == '0') {
                    ans[i] = '1';
                    break;
                }
            }
        }
        return ans;
    }
};