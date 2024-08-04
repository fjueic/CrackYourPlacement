class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> t;
        set<int>s;
        for(int i:nums){
            if(s.find(i)!=s.end())continue;
            s.insert(i);
            t.push_back(i);
        }
        sort(t.begin(),t.end());
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
