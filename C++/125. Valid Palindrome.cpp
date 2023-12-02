class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.size() - 1;
        while (head <= tail){
            if (!isalnum(s[head])) {head++; continue;}
            // isalnum() ��k??�r�Ŧ�O�_�Ѧr���M?�r?���C
            if (!isalnum(s[tail])) {tail--; continue;}
            // C++ ���� continue ?�y��?�� break ?�y�C�������O?��?��Acontinue ?��??�e�`?�����N?�A?��?�l�U�@���`?�C
            if (tolower(s[head]) != tolower(s[tail])) return false;
            // tolower()��?: ��r��??���p?�r���C
            else{
                head++;
                tail--;
            }
        }
        return true;
    }
};
// Refer to msfxvenom's solution