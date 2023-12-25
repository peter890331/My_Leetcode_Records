class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        //cout<<"n="<<n<<endl;
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        //print(dp);
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') dp[i] += dp[i+1];
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
                dp[i] += dp[i+2];
            //cout<<endl;
            //print(dp);
        }
        return dp[0];
    }

    void print(vector<int> v){
        for (int i: v) cout << i << ' ';
    }

};

// Dynamic programming.

// lancertech6's solution, 
// Initialize a dynamic programming array dp of length n + 1, where n is the length of the input string s. Set dp[n] = 1 since there is one way to decode an empty string.
// Iterate backward through the string from n - 1 to 0.
// If the current character is not '0', set dp[i] to dp[i + 1], indicating that we can decode the current digit individually.
// 如果當前字符可以單獨解碼，先假設解碼方法數和後一串字相同，因為只是多加了一個字符。
// If the current and the next character form a valid two-digit number ('10' to '26'), add dp[i + 2] to dp[i]. This accounts for the possibility of decoding the current digit along with the next digit.
// 如果當前字符又和後一個字符可以組成另一種解碼方式，就再加上後兩個字符的解法方法數。
// The final answer is stored in dp[0], representing the number of ways to decode the entire string.