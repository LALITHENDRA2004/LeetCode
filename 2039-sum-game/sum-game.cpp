class Solution {
public:
    bool sumGame(string num) {
        int i = 0, j = num.size() - 1, ls = 0, rs = 0, lq = 0, rq = 0;
        for(int i = 0 ; i < num.size() ; i++) {
            if(i < num.size() / 2) {
                if(num[i] == '?') lq++;
                else ls += num[i] - '0';
            }
            else {
                if(num[i] == '?') rq++;
                else rs += num[i] - '0';
            }
        }
        cout << ls << " " << rs << " " << lq << " " << rq << endl; 
        if((lq + rq) % 2 != 0) return true;

        if(lq < rq) rq -= lq, lq = 0;
        else if(rq < lq) lq -= rq, rq = 0;
        else lq = 0, rq = 0;

        if(lq == 0 && rq == 0 && ls == rs) return false;
        if(lq == 0) {
            if(ls > rs) {
                int bob = rq / 2;
                if(((rq - bob) * 9) + rs > ls) return true;
                else if(rs + (bob * 9) >= ls) return false;
                else return true;
            }
            else {
                return true;
            }
        }
        else {
            if(ls < rs) {
                int bob = lq / 2;
                if(ls + (lq - bob) * 9 > rs) return true;
                if(ls + (bob * 9) >= rs) return false;
                else return true;
            }
            else {
                return true;
            }
        }
    }
};