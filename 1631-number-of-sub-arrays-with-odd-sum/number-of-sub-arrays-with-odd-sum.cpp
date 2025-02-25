class Solution {
public:
    #define ll long long
    int numOfSubarrays(vector<int>& arr) {
        ll eves = 0, odds = 0, sum = 0, cnt = 0, mod = 1e9 + 7;
        for(int i = 0 ; i < arr.size() ; i++) {
            sum += arr[i];
            if(sum % 2 == 0) {
                cnt = (cnt % mod + odds % mod) % mod;
                eves++;
            }
            else {
                cnt = (cnt % mod + 1 + eves % mod) % mod;
                odds++;
            }
        }
        return cnt % mod;
    }
};