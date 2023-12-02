class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector <int> chars_counts(26, 0);
        
        for (const char& ch: chars){
            chars_counts[ch - 'a']++;         
            //char的底層表示的是ASCII碼，[ch - 'a']表示以ch的ASCII值減去'a'的ASCII值，
            //在ASCII碼中，小寫字母'a'到'z'分別對應到整數值97到122。因此，可以通過減去'a'的ASCII值，將字符映射為0到25的整數。
        }
        int result = 0;
        for (const string& word: words){
            if (canForm(word, chars_counts)){
                result += word.size();
            }
        }
        return result;
    }

    bool canForm (const string& word, const vector <int>& chars_counts){
        vector <int> words_counts(26, 0);
        for (const char& ch: word){
            int temp = ch - 'a';
            words_counts[temp]++;
            if (words_counts[temp] > chars_counts[temp]) return false;
        }
        return true;
    }
};

// Refer to lancertech6's solution