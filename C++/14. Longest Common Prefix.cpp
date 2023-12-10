class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string template_ = strs[0];
        for (const string& str: strs){
            while (str.find(template_)!=0){
                template_ = template_.substr(0, template_.size()-1);
            }
        }
        return template_;
    }
};

// Reference from ayeshakalsoom06's solution.
// str.find(template_)，如果有找到的話會回傳找到的位置，如果沒有找到會回傳"npos"。