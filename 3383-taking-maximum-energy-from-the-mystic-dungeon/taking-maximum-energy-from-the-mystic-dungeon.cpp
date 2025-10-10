class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // -2 -3 -1

        vector<int> dummy = energy;
        int maxi = INT_MIN;
        for(int i = dummy.size() - 1 ; i >= 0 ; i--) {
            if(i + k < dummy.size()) {
                dummy[i] += dummy[i + k];
            }
            maxi = max(maxi, dummy[i]);
        }
        return maxi;
    }
};