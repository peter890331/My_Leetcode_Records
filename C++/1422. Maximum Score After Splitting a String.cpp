class Solution {
public:
    int maxScore(string s) {
        int zeros = 0;
        int ones = 0;
        for (const char& ch: s){
            if (ch=='0') zeros++;
            else if (ch=='1') ones++;
        }
        int result = 0;
        int zeros_ = 0;
        int ones_ = 0;
        for (int i=0; i<s.size()-1; i++){
            if (s[i]=='0'){
                zeros_++;
                result = max((zeros_+ones-ones_), result);
            }
            else if (s[i]=='1'){
                ones_++;
                result = max((zeros_+ones-ones_), result);
            }
        }
        return result;
    }
};