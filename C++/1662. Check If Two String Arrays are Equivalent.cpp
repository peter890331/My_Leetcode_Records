class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string merge_word1 = "";
        string merge_word2 = "";
        for (const string& s1: word1) merge_word1 += s1;
        for (const string& s2: word2) merge_word2 += s2;
        //sort(merge_word1.begin(), merge_word1.end());
        //sort(merge_word2.begin(), merge_word2.end());
        return merge_word1==merge_word2;
    }
};