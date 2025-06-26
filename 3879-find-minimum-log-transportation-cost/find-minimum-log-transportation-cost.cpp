class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long minCost = 0;
        long log1, log2;
        if(n > k) {
            log1 = n - k;
            log2 = n - log1;

            minCost += log1 * log2;
        }
        if(m > k) {
            log1 = m - k;
            log2 = m - log1;

            minCost += log1 * log2;
        }

        return minCost;
    }
};