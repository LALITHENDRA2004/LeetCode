class Solution {
public:
    int findLucky(vector<int>& arr) {
        int luckyNumber = -1;
        map<int, int> count;
        for(int i = 0 ; i < arr.size() ; i++) {
            count[arr[i]]++;
        }
        for(int i = 0 ; i < arr.size() ; i++) {
            if(arr[i] == count[arr[i]]) {
                luckyNumber = max(luckyNumber, arr[i]);
            }
        }
        return luckyNumber;

    }
};