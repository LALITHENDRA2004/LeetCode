class Solution {
public:
    bool isValid(string word) {
        int digits = 0, letters = 0, vowels = 0, consonants = 0;
        string v = "aeiouAEIOU";
        for(int i = 0 ; i < word.size() ; i++) {
            if(word[i] >= '0' && word[i] <= '9') digits++;
            else if((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
                letters++;
                bool isVowel = false;
                for(int j = 0 ; j < v.size() ; j++) {
                    if(word[i] == v[j]) {
                        isVowel = true;
                        break;
                    }
                }
                if(isVowel) vowels++;
                else consonants++;
            }
        }

        int total = digits + letters;
        cout << digits << " " << letters << " " << vowels << " " << consonants << endl;
        if(total >= 3 && total == word.size() && vowels >= 1 && consonants >= 1) return true;
        return false;
    }
};