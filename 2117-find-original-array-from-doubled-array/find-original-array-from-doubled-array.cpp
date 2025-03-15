class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        multiset<int> ms;
        int cnt = 0;
        for(int i : changed) {
            if(i != 0) ms.insert(i);
            else cnt++;
        }
        if(cnt % 2 != 0) return {};

        sort(changed.begin(), changed.end());
        vector<int> ans;
        for(int i : changed) {
            auto it1 = ms.find(i);
            int doub = i * 2;

            auto it2 = ms.find(doub);
            if(it1 != ms.end() && it2 != ms.end()) {
                ans.push_back(i);
                ms.erase(it1);
                ms.erase(it2);
            }
        }
        if(ms.size() != 0) return {};

        for(int i = 0 ; i < cnt / 2 ; i++) ans.push_back(0);
        return ans;
        
    }
};