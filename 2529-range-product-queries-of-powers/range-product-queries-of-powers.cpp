class Solution {
public:
    long multiply(long a, long b) {
        long mod = 1e9 + 7;
        return ((a % mod) * (b % mod)) % mod;
    }
    void build(int ind, int low, int high, vector<int>& arr, vector<long>& seg) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr, seg);
        build(2 * ind + 2, mid + 1, high, arr, seg);
        seg[ind] = multiply(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    long queryProduct(int ind, int ql, int qr, int l, int r, vector<long> &seg) {
        if(l >= ql && r <= qr) return seg[ind];
        if(l > qr || r < ql) return 1;
        int mid = l + (r - l) / 2;
        int left = queryProduct(2 * ind + 1, ql, qr, l, mid, seg);
        int right = queryProduct(2 * ind + 2, ql , qr, mid + 1, r, seg);
        return multiply(left, right);
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int x = (1 << 31);
        
        int n1 = n;
        while(!(n1 & x)) {
            x = x >> 1;
        }
        x = -x;

        vector<int> arr;
        int sum = 0;
        while(sum < n1) {
            if(sum + x <= n1) {
                sum += x; // 14
                arr.push_back(x); // 8 4 2
            }
            x /= 2; // 4 2 1
        } 
        reverse(arr.begin(), arr.end());

        for(int i : arr) cout << i << " "; 
        cout << endl;
        vector<long> seg(arr.size() * 4);
        build(0, 0, arr.size() - 1, arr, seg);

        for(int i : seg) cout << i << " "; 
        vector<int> ans(queries.size());
        for(int i = 0 ; i < queries.size() ; i++) {
            ans[i] = queryProduct(0, queries[i][0], queries[i][1], 0, arr.size() - 1, seg);
        } 
        
        return ans;
    }
};