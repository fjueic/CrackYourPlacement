class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> stk;
        for(char c:S){
            if(c>='0' && c<='9'){
                stk.push(c-'0');
            }else{
                int y=stk.top();stk.pop();
                int x=stk.top();stk.pop();
                if(c=='+')stk.push(x+y);
                if(c=='/')stk.push(x/y);
                if(c=='-')stk.push(x-y);
                if(c=='*')stk.push(x*y);
            }
        }
        return stk.top();
    }
};
