class Solution {
public:
    bool halvesAreAlike(string s) {
        int len_s = s.size();
        int len_s_2 = s.size()/2;
        string s1 = s.substr(0, len_s_2);
        string s2 = s.substr(len_s_2, len_s);
        // print(s1);
        // cout<<endl;
        // print(s2);
        int count1 = 0;
        int count2 = 0;
        for (int i=0; i<len_s_2; i++){
            if(s1[i] == 'a' or s1[i] == 'e' or s1[i] == 'i' or s1[i] == 'o' or s1[i] == 'u' or 
                s1[i] == 'A' or s1[i] == 'E' or s1[i] == 'I' or s1[i] == 'O' or s1[i] == 'U')
                count1++;
            if(s2[i] == 'a' or s2[i] == 'e' or s2[i] == 'i' or s2[i] == 'o' or s2[i] == 'u' or 
                s2[i] == 'A' or s2[i] == 'E' or s2[i] == 'I' or s2[i] == 'O' or s2[i] == 'U')
                count2++;
        }
        return count1 == count2;
    }

    void print(string s){
        for (int i=0; i<s.size(); i++) cout<<s[i]<<',';
    }
};