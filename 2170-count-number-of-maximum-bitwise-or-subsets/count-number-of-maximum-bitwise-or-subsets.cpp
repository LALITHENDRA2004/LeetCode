class Solution {
public:
    void countMaxOr(vector<int> v, int i, unordered_map<int, int> &cnt, int o) {
        if(i >= v.size()) {
            cnt[o]++;
            return;
        }

        countMaxOr(v, i + 1, cnt, o | v[i]);

        countMaxOr(v, i + 1, cnt, o);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> cnt;
        countMaxOr(nums, 0, cnt, 0);

        int key = 0, value = 0;
        for(auto i : cnt) {
            if(i.first > key) {
                key = i.first;
                value = i.second;
            }
        }

        return value;
    }
};