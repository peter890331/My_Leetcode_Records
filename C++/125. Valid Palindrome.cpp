class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.size() - 1;
        while (head <= tail){
            if (!isalnum(s[head])) {head++; continue;}
            // isalnum() 方法??字符串是否由字母和?字?成。
            if (!isalnum(s[tail])) {tail--; continue;}
            // C++ 中的 continue ?句有?像 break ?句。但它不是?迫?止，continue ?跳??前循?中的代?，?迫?始下一次循?。
            if (tolower(s[head]) != tolower(s[tail])) return false;
            // tolower()函?: 把字符??成小?字母。
            else{
                head++;
                tail--;
            }
        }
        return true;
    }
};
// Refer to msfxvenom's solution