class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map <char, int> Roman;
        Roman['I'] = 1;
        Roman['V'] = 5;
        Roman['X'] = 10;
        Roman['L'] = 50;
        Roman['C'] = 100;
        Roman['D'] = 500;
        Roman['M'] = 1000;
        for (int i=0; i<s.size(); i++){
            if (Roman[s[i]]<Roman[s[i+1]]) result -= Roman[s[i]];
            else result += Roman[s[i]];
        }
        return result;
    }
};

// Reference from rahulvarma5297's solution.
// 通常，羅馬數字的表示方式是由左到右，將所有的數字相加。但是，如果左邊的數字比右邊的數字小，則減去左邊的數字的值。