class Spreadsheet {
public:
    vector<vector<int>> arr;
    Spreadsheet(int rows) {
        arr.resize(rows+1, vector<int> (26, 0));
    }

    int toInt(string s) {
        int num = 0, i = 0;
        while(i < s.size()) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        return num;
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        string s = cell.substr(1);
        int row = toInt(s);
        arr[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        string s = cell.substr(1);
        int row = stoi(s);
        arr[row][col] = 0;
    }

    int find(string str, int ind) {
        int val = 0;
        if(str[ind] >= 'A' && str[ind] <= 'Z') {
            int col1 = str[ind] - 'A';

            ind++;
            
            int row1 = 0;
            while(ind < str.size() && str[ind] != '+') {
                row1 = row1 * 10 + (str[ind] - '0');
                ind++;
            }

            val = arr[row1][col1];
        }
        else {
            while(ind < str.size() && str[ind] != '+') {
                val = val * 10 + (str[ind] - '0');
                ind++;
            }
        }

        return val;
    }
    
    int getValue(string formula) {
        int val1 = find(formula, 1);

        int i = 1;
        while(i < formula.size() && formula[i] != '+') i++;
        i++;

        int val2 = find(formula, i);

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */