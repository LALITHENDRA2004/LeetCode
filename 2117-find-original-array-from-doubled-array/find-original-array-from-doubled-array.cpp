class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 != 0) return {};
        map<int, int> cnt;
        for(int i : changed) cnt[i]++;

        vector<int> ans;
        sort(changed.begin(), changed.end());
        for(int i : changed) {
           if(i != 0 && cnt[i] > 0) {
                if(cnt[2 * i] > 0) {
                    cnt[i]--;
                    cnt[2 * i]--;
                    ans.push_back(i);
                }
            }
        }
        if(cnt[0] % 2 != 0) return {};
        for(int i = 0 ; i < cnt[0] / 2 ; i++) {
            ans.push_back(0);
        }
        if(ans.size() == changed.size() / 2) return ans;
        return {};


    }
};