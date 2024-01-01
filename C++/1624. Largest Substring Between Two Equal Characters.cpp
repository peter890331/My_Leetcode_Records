class Solution {
public:
    int maxLengthBetweenEqualCharacters(std::string s) {
        int first = 0;
        int end = s.size() - 1;
        int result = -1;
        // cout<<end;
        for (int i=0; i<=end; i++){
            for (int j=end; j>i; j--){
                //cout<<i<<','<<j<<endl;
                if (s[i] == s[j]) result = max(j-i-1, result);
            }
        } 
        return result == -1 ? -1: result;
    }
};