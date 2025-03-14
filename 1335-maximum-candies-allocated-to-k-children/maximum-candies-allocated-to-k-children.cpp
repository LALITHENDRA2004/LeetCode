class Solution {
public:
    #define ll long long
    ll find(ll pile, vector<int> &candies) {
        ll cnt = 0;
        for(ll i = 0 ; i < candies.size() ; i++) {
            cnt += candies[i] / pile;
        }
        return cnt;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        ll low = 0, high = 1e7;
        ll ans = 0;
        while(low <= high) {
            ll mid = (low + high) / 2;
            if(mid == 0) return high;
            ll res = find(mid, candies);
            if(res < k) {
                high = mid - 1;
            }
            else{
                low = mid + 1;
                ans = max(ans, mid);
            }
        }
        return ans;
    }
};