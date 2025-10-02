class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fullBottles = numBottles; // 10
        int emptyBottles = 0;
        int totalBottles = 0;
        while(fullBottles != 0) {
            totalBottles += fullBottles; // 10 12
            emptyBottles += fullBottles; // 10
            fullBottles = 0; // 0
            while(emptyBottles >= numExchange) {
                fullBottles++; // 1 2
                // totalBottles++; // 11 12
                emptyBottles -= numExchange; // 7 3
                numExchange++; // 4 5
            }
        }
        return totalBottles;
    }
};