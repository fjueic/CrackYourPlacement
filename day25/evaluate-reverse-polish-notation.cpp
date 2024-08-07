class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string s:tokens){
            if(s=="/"){
                int y=stk.top();stk.pop();
                int x=stk.top();stk.pop();
                stk.push(x/y);
            }else if(s=="*"){
                int y=stk.top();stk.pop();
                int x=stk.top();stk.pop();
                stk.push(x*y);
            }else if(s=="+"){
                int y=stk.top();stk.pop();
                int x=stk.top();stk.pop();
                stk.push(x+y);
            }else if(s=="-"){
                int y=stk.top();stk.pop();
                int x=stk.top();stk.pop();
                stk.push(x-y);
            }else{
                stk.push(stoi(s));
            }

        }
        return stk.top();
    }
};
