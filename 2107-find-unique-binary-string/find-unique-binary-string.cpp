class Solution {
public:
void find(string s, int &ind, string &ans, vector<string> &nums) {
    if (ans != "") return; // If we've already found an answer, return
    if (s.size() == nums.size()) {
        // Check if the current string is not in nums
        if (ind >= nums.size() || nums[ind] != s) {
            ans = s; // Assign the missing string to ans
            return;
        }
        ind++; // Move to the next string in nums
        return;
    }
    s += "0";
    find(s, ind, ans, nums);
    s.pop_back();
    s += "1";
    find(s, ind, ans, nums);
    //s.pop_back();
}
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end()); // Sort the input array
    int ind = 0;
    string s = "", ans = "";
    find(s, ind, ans, nums); // Start generating binary strings
    return ans;
    }
};