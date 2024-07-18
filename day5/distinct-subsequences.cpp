class Solution {
public:
    int solve(string s,string t,int i,int j,vector<vector<int>> &dp){
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=(s[i]==t[j]?
                solve(s,t,i+1,j+1,dp):0)
                +solve(s,t,i+1,j,dp);

    }
    int numDistinct(string s, string t) {
        int l1=s.size();
        int l2=t.size();
        vector<vector<unsigned long long>> dp(l1+1,vector<unsigned long long>(l2+1,0));
        for(int i=l1;i>=0;i--){
            dp[i][l2]=1;
        }
        for(int i=l1-1;i>=0;i--){
            for(int j=l2-1;j>=0;j--){
                dp[i][j]=dp[i+1][j];
                if(s[i]==t[j])dp[i][j]+=dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};
