class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int canDrink = numBottles;
        while(numBottles >= numExchange) {
            canDrink += numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }
        return canDrink;
    }
};