class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> mat;
        mat.push_back(meetings[0]);

        int ind = 0;
        for(int i = 1 ; i < n ; i++) {
            if(meetings[i][0] <= mat[ind][1]) {
                if(meetings[i][1] > mat[ind][1]) {
                    mat[ind][1] = meetings[i][1];
                }
            }
            else {
                mat.push_back(meetings[i]);
                ind++;
            }
        }

        int kaali = mat[0][0] - 1;
        for(int i = 1 ; i < mat.size() ; i++) {
            kaali += mat[i][0] - mat[i - 1][1] - 1;
        }
        kaali += days - mat[mat.size() - 1][1];

        return kaali;
    }
};