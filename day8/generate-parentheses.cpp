class Solution {
public:
    void solve(vector<string> &ans,string &s,int opening,int closing,int n){
        if(s.size()==n*2){
            ans.push_back(s);
            return ;
        }
        if(closing<n && closing<opening){
            s.push_back(')');
            solve(ans,s,opening,closing+1,n);
            s.pop_back();
        }
        if(opening <n){
            s.push_back('(');
            solve(ans,s,opening+1,closing,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string a="";
        solve(ans,a,0,0,n);
        return ans;
    }
};
