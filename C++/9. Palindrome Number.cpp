class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        else{
            string x_ = to_string(x);
            int i = 0;
            int j = x_.size()-1;
            while(i<=j){
                if (x_[i]==x_[j]){
                    i++; j--;
                }
                else return false;
            }
            return true;
        }
    }
};