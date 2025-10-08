class Solution {
public:
    int findSuccessfulPairs(int spell, vector<int> &potions, long long success) {
        int low = 0, high = potions.size() - 1;
        int ind = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long product = (1LL) * spell * potions[mid];
            if(product >= success) {
                ind = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ind == INT_MAX ? 0 : potions.size() - ind;

    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(int i = 0 ; i < spells.size() ; i++) {
            int cnt = findSuccessfulPairs(spells[i], potions, success);
            ans.push_back(cnt);
        }
        return ans;
    }
};