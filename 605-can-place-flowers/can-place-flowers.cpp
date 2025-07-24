class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1 && flowerbed[0] == 0) return true;
        int last = -2;
        for(int i = 0 ; i < flowerbed.size() - 1 ; i++) {
            if(flowerbed[i] == 1) last = i;
            else if(last != i - 1 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                last = i;
                n--;
            }
        }
        int l = flowerbed.size() - 1;
        if(flowerbed[l] == 0 && flowerbed[l - 1] == 0 && l - 2 == last) n--;
        return n <= 0;
    }
};