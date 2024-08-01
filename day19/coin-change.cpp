class Solution {
public:
    int solve(vector<int>&coins,int amount,int i,vector<vector<int>>&dp){
        if(i==0){
            if(amount%coins[i]==0){
                return amount/coins[i];
            }
            return 1e9;
        }
        if(dp[amount][i]!=-1)return dp[amount][i];
        int ans=1e9;
        if(amount>=coins[i]){
            ans=min(ans,solve(coins,amount-coins[i],i,dp))+1;
        }
        ans=min(ans,solve(coins,amount,i-1,dp));
        return dp[amount][i]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),1e9));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
                dp[i][0]=i/coins[0];
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int a=1e9;
                if(j>=coins[i]){
                    a=min(a,dp[j-coins[i]][i])+1;
                }
                a=min(a,dp[j][i-1]);
                dp[j][i]=a;
            }
        }
        int ans=dp[amount][coins.size()-1];
        if(ans==1e9)ans=-1;
        return ans;
    }
};
