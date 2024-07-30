class Solution {
public:
    string solve(string str){
        stack<char>s;
        for(char c:str){
            if(c=='#')s.pop();
            else s.push(c);
        }
        string ans;
        while(!s.empty()){
            ans+=s.top();s.pop();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        return solve(s)==solve(t);
    }
};
