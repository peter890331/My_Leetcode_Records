class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()){
            seen.insert(n);
            n = check(n);
        }
        return (n==1)? true : false;
    }
    int check(int &n){
        int temp = 0;
        string n_ = to_string(n);
        for (const char& ch: n_){
            temp += pow((ch-'0'), 2);
        }
        return temp;
    }
};