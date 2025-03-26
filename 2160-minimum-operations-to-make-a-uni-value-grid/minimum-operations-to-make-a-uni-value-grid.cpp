class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        multiset<int> ms;
        for(auto i : grid) {
            for(int j : i) {
                ms.insert(j);
            }
        }

        int mid = ms.size() / 2, ele = 0;
        for(int i : ms) {
            if(mid == 0) {
                ele = i;
                break;
            }
            mid--;
        }

        int ans = 0;
        for(int i : ms) {
            if(abs(i - ele) % x != 0) return -1;
            else ans += abs(i - ele) / x;
        }
        return ans;

    }
};