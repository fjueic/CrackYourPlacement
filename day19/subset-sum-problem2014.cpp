class Solution{
public:
    bool subsetSum(int n,int arr[],int s,int i,vector<vector<int>> &dp){
        if(s==0)return 1;
        if(i==n)return 0;
        if(dp[s][i]!=-1)return dp[s][i];
        bool ans=subsetSum(n,arr,s,i+1,dp);
        if(ans)return dp[s][i]=ans;
        if(s>=arr[i]){
            ans |=subsetSum(n,arr,s-arr[i],i+1,dp);
        }
        return dp[s][i]=ans;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)sum+=arr[i];
        if(sum%2==1)return 0;
        vector<vector<int>> dp(sum/2+1,vector<int>(N+1,-1));
        return subsetSum(N,arr,sum/2,0,dp);
    }
};
