class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<char, int> check;             // <字符, 字符最後出現的位置>
        int first = 0;

        for (int i=0; i<s.size(); i++){
            // not found
            if (check.find(s[i])==check.end() || check[s[i]]<first){
                result = max(result, i-first+1);    // 未找到或者重复字符不在当前窗口中，更新结果
            }
            // found
            else {     
                first = check[s[i]] + 1;            // 重复字符在当前窗口中，移动窗口起始位置到重复字符的下一个位置
            }
            check[s[i]] = i;                        // 更新字符在字符串中的最新位置
        }
        return result;
    }
};