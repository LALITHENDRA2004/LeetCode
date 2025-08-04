class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int fruitsCnt = 0;
        int maxi = INT_MIN;
        int size = 0;
        int j = 0;
        map<int, int> cnt;
        for(int i = 0 ; i < fruits.size() ; i++) {
            if(cnt[fruits[i]] == 0) size++;
            cnt[fruits[i]]++;

            fruitsCnt++;
            while(size > 2) {
                cnt[fruits[j]]--;
                if(cnt[fruits[j]] == 0) {
                    size--;
                }
                j++;
                fruitsCnt--;
            }

            maxi = max(maxi, fruitsCnt);
        }
        return maxi;
    }
};