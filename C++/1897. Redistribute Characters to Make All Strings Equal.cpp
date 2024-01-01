class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> check(26, 0);
        for (const string s: words){
            for (const char ch: s){
                check[ch - 'a']++;
            }
        }
        for (int i : check){
            if (i % words.size() != 0) return false;
        }
        return true;
    }
};

// Reference from lancertech6's solution.