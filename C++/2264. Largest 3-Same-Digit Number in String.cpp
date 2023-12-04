class Solution {
public:
    string largestGoodInteger(string num) {
        string temp = "";
        for (int i=0; i<num.size()-2; i++){
            if (num[i] == num[i+1] && num[i+1] == num[i+2]){
                temp = max(temp, num.substr(i,3));
            }
        }
        return temp;
    }
};

// substr 就是從字串中擷取出一段子字串的一個成員函式，substr 可使指定子字串的起始位置一直到結束字元，substr 也可以子字串的指定起始位置跟長度。

// string 也可以比大小。