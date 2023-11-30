class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> s_mp;
        unordered_map <char, int> t_mp;
        for (int i=0; i<s.size(); i++){
            s_mp[s[i]] +=1;
        }
        for (int i=0; i<t.size(); i++){
            t_mp[t[i]] +=1;
        }
        return s_mp==t_mp;
    }
};