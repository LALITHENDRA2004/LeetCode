class Solution {
public:
    vector<int> addRow(int row) {
        int ans = 1;
        vector<int> arr;
        arr.push_back(1);

        for(int i = 0 ; i < row ; i++) {
            ans = ans * (row - i);
            ans = ans / (i + 1);
            arr.push_back(ans);
        }
        return arr;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0 ; i < numRows ; i++) {
            vector<int> temp = addRow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};