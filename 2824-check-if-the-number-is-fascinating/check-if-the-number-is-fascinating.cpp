class Solution {
public:
    bool isFascinating(int n) {
        if(n * 2 > 1000 || n * 3 > 1000) return false;
        long num = (((n * 1000) + (2 * n)) * 1000) + (3 * n);
        int sum = 0;
        map<int, int> arr;
        while(num != 0) {
            int rem = num % 10;
            arr[rem]++;
            if(rem == 0 || arr[rem] > 1) return false;
            sum += rem;
            num = num / 10;

            cout << rem << " " << arr[rem] << endl;
        }
        //129258387
        cout << endl << arr.size();
        return arr.size() == 9 ? true : false;
    }
};