class Solution {
public:
    #define ll long long
    int minimumTotal(vector<vector<int>>& triangle) {
        ll rows = triangle.size() - 1, cols = triangle[rows].size() - 1;

        vector<ll> prev(cols + 1, INT_MAX), curr(cols + 1, INT_MAX);

        prev[0] = triangle[0][0];
        ll ans = INT_MAX;

        for(ll i = 1 ; i <= rows ; i++) {
            for(ll j = 0 ; j < triangle[i].size() ; j++) {
                ll mini = INT_MAX;

                ll one = triangle[i][j] + prev[j], two = INT_MAX;
                if(j-1 >= 0) two = triangle[i][j] + prev[j-1];

                curr[j] = min(one, two);

                if(i == rows) {
                    ans = min(ans, curr[j]);
                }
            }
            prev = curr;
        }
        return ans == INT_MAX ? triangle[0][0] : ans;
    }
};