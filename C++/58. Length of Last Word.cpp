class Solution {
public:
    int lengthOfLastWord(string s) {
        int flag = 0;
        int result = 0;
        for (int i=s.size()-1; i>=0; i--){
            if (s[i] != ' '){
                flag = 1;
                result ++;
            }
            if (s[i] == ' ' && flag != 0){
                break;
            }
        }
        return result;
    }
};

// Reference from wasifkader's solution, use a flag, so smart!