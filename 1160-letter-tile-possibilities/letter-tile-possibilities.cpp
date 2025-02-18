class Solution {
public:
    void find(string &t, string &s, vector<bool> &used, int &cnt) {
        for(int i = 0 ; i < t.size() ; i++) {
            if(used[i]) continue;
            if(i > 0 && t[i] == t[i - 1] && !used[i - 1]) continue;

            s += t[i];
            cnt++;
            used[i] = true;

            find(t, s, used, cnt);

            used[i] = false;
            s.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> used(tiles.size(), false);
        string s = "";
        int cnt = 0;
        find(tiles, s, used, cnt);
        return cnt;
    }
};