class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result = 0;
        int cookie_ = s.size() - 1;
        int child_ = g.size() - 1;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(cookie_ >= 0 && child_ >=0){
            if(s[cookie_] >= g[child_]){
                result++;
                cookie_--;
                child_--;
            }
            else child_--;
        }
        return result;
    }
};