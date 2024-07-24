class Solution {
public:
    int largestRectangleArea(vector<int>& t) {
        int ans=0;
        int n=t.size();
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            if(s.empty() || s.top().first<=t[i]){
                s.push({t[i],i});
            }else{
                int ele=t[i],idx=i;
                while(!s.empty() &&s.top().first>t[i]){
                    pair<int,int> x=s.top();s.pop();
                    ans=max(ans,x.first*(i-x.second));
                    idx=x.second;
                }
                s.push({ele,idx});
            }
        }
        while(!s.empty()){
            pair<int,int> x=s.top();s.pop();
            ans=max(ans,x.first*(n-x.second));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> dp(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0')dp[j]=0;
                else dp[j]+=1;
            }
            ans=max(ans,largestRectangleArea(dp));
        }
        return ans;
    }
};
