class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int> placed(fruits.size(), 0);
        int cnt = 0;
        for(int i = 0 ; i < fruits.size() ; i++) {
            for(int j = 0 ; j < baskets.size() ; j++) {
                if(placed[j] == 0) {
                    if(baskets[j] >= fruits[i]) {
                        placed[j] = 1;
                        cnt++;
                        break;
                    }
                }
            }
        }
        int remaining = fruits.size() - cnt;
        return remaining;
    }
};