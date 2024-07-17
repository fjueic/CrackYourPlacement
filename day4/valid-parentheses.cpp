class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ')') {
                if (stk.empty())
                    return 0;

                if (stk.top() == '(')
                    stk.pop();
                else
                    return 0;
            } else if (c == ']') {
                if (stk.empty())
                    return 0;

                if (stk.top() == '[')
                    stk.pop();
                else
                    return 0;
            } else if (c == '}') {
                if (stk.empty())
                    return 0;

                if (stk.top() == '{')
                    stk.pop();
                else
                    return 0;
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
