class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> list(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        int len = 0;
        while(!q.empty()) {
            string word = q.front().first;
            len = q.front().second;
            //cout << word << endl;
            if(word == endWord) return len;
            q.pop();

            for(int i = 0 ; i < word.size() ; i++) {
                string temp = word;
                for(char c = 'a' ; c <= 'z' ; c++) {
                    temp[i] = c;
                    //cout << word << endl;
                    if(list.find(temp) != list.end()) {
                        q.push({temp, len + 1});
                        list.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};