class Solution {
public:
    int minOperations(string s) {
        int result1 = 0;
        int flag1 = s[0]-'0';
        int result2 = 1;
        int flag2 = (s[0]-'0' == 0)? 1 :0;
        for (int i=1; i<s.size(); i++){
            int ch = s[i]-'0';
            check(ch, result1, flag1);
            check(ch, result2, flag2);
        }
        return min(result1, result2);
    }
    void check(int &ch, int &result, int &flag){
        if (flag==0 && ch==0){
            result++; 
            flag = 1;
        } 
        else if (flag==1 && ch==1){
            result++;
            flag = 0;
        }
        else flag = ch;
    }
};