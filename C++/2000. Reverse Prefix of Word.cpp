class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = word.find(ch);
        if (j != -1) {
            reverse(word.begin(), word.begin() + j + 1);
        }
        return word;
    }
};

// Mohammed_Raziullah_Ansari's solution.
// STL 已經有提供 reverse 函式可以使用了，C++11 才加入的，只需 #include <algorithm> 並且加入 -std=c++11 編譯選項就可使用。
// https://shengyu7697.github.io/cpp-string-reverse/.
