class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<int> pre=matrix[0];
        for(int x:pre){
            ans+=x;
        }
        for(int i=1;i<m;i++){
            vector<int> cur=matrix[i];
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0)continue;
                cur[j]=min(min(cur[j-1],pre[j]),pre[j-1])+1;
            }
            pre=cur;
            for(int x:pre){
                ans+=x;
            }
        }
        return ans;
    }
};
