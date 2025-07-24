class Solution {
public:
    int numSplits(string s) {
        map<char, int> mp;
        set<char> ms;
        for(int i = 0 ;i < s.size() ;i++) {
            mp[s[i]]++;
        }

        int cnt = 0, ans = 0, dis = mp.size();
        for(int i = 0 ; i < s.size() ; i++) {
            mp[s[i]]--;
            if(mp[s[i]] == 0) cnt++;
            ms.insert(s[i]);

            int ld = ms.size();
            int rd = dis - cnt;
            if(ld == rd) ans++;
        }
        return ans;
    }
};