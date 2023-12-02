class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector <int> chars_counts(26, 0);
        
        for (const char& ch: chars){
            chars_counts[ch - 'a']++;         
            //char�����h��ܪ��OASCII�X�A[ch - 'a']��ܥHch��ASCII�ȴ�h'a'��ASCII�ȡA
            //�bASCII�X���A�p�g�r��'a'��'z'���O�������ƭ�97��122�C�]���A�i�H�q�L��h'a'��ASCII�ȡA�N�r�ŬM�g��0��25����ơC
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