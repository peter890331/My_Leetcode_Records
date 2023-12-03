class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_;
        for (char& i: s){
            if (i == '(' || i == '{' || i == '[') stack_.push(i);
            else{
                if (stack_.empty() ||
                    (i == ')'  && stack_.top() != '(') ||
                    (i == '}'  && stack_.top() != '{') ||
                    (i == ']'  && stack_.top() != '[')) 
                    return false;
                    stack_.pop();
            }
        }
        return stack_.empty();
    }
};

// stack 堆疊，後進先出原則(LIFO，Last In First Out)，常用基本的操作方法有 push()、pop()、top()。