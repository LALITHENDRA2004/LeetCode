class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evens = 0, odds = 0, eveOdds = 0, oddEves = 0;
        bool prevIsEven = false, prevIsOdd = false;
        for(int i = 0 ; i < nums.size() ; i++) 
        {
            if(nums[i] % 2 == 0) evens++;
            else odds++;

            if(oddEves == 0 && nums[i] % 2 != 0) 
            {
                oddEves++;
                prevIsOdd = true;
            }
            else 
            {
                if(prevIsOdd == false && nums[i] % 2 != 0)
                {
                    prevIsOdd = true;
                    oddEves++;
                }
                else if(prevIsOdd == true && nums[i] % 2 == 0) 
                {
                    prevIsOdd = false;
                    oddEves++;
                }
            }

            if(eveOdds == 0 && nums[i] % 2 == 0)
            {
                eveOdds++;
                prevIsEven = true;
            }
            else 
            {
                if(prevIsEven == false && nums[i] % 2 == 0) {
                    prevIsEven = true;
                    eveOdds++;
                }
                else if(prevIsEven == true && nums[i] % 2 != 0) {
                    prevIsEven = false;
                    eveOdds++;
                }
            }

        }

        int max1 = max(evens, odds);
        int max2 = max(eveOdds, oddEves);
        return max(max1, max2);
    }
};