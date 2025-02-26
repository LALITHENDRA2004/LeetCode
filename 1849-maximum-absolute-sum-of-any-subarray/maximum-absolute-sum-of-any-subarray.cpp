class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        int maxi = prefix[0], mini = prefix[0], ind1 = 0, ind2 = 0;
        for(int i = 1 ; i < nums.size() ; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
            if(prefix[i] > maxi) {
                maxi = prefix[i];
                ind1 = i;
            }
            if(prefix[i] < mini) {
                mini = prefix[i];
                ind2 = i;
            }
        }

        cout << maxi << " is at " << ind1 << endl << mini << " is at " << ind2 << endl;

        for(int i : prefix) cout << i << " ";
        cout << endl;

        //int m1 = abs(maxi), m2 = abs(mini);
        int lpmForm1 = 0, lnmForm1 = 0, lpmForm2 = 0, lnmForm2;
        for(int i = 0 ; i <= max(ind1 - 1, ind2 - 1) ; i++) {
            if(i <= ind1 - 1) {
                lpmForm1 = max(lpmForm1, prefix[i]);
                lnmForm1 = min(lnmForm1, prefix[i]);
            }
            if(i <= ind2 - 1) {
                lpmForm2 = max(lpmForm2, prefix[i]);
                lnmForm2 = min(lnmForm2, prefix[i]);
            }
        }

        //cout << "m1 = " << m1 << endl << "m2 = " << m2 << endl;
        cout << lpmForm1 << " " << lnmForm1 << endl << lpmForm2 << " " << lnmForm2 << endl;

        int ans1 = 0, ans2 = 0;
        if(maxi < 0) {
            // requires left positive max
            ans1 = abs(maxi - lpmForm1);
        }
        else {
            // requires left negative max (abs) 5 - (-100) 
            ans1 = maxi - lnmForm1;
        }

        if(mini < 0) {
            // requires left positive max if not itself is the answer
            ans2 = abs(mini - lpmForm2);
        }
        else {
            // requires left negative max
            ans2 = mini - lnmForm2;
        }
        return max(ans1, ans2);

        
    }
};