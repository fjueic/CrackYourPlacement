class Solution {
public:
    void once(vector<int>&ans,vector<vector<int>>&m, int a,int b,int c,int d){
        for(int i=d;i<=b;i++){
            ans.push_back(m[a][i]);
        }
        for(int i=a+1;i<=c;i++){
            ans.push_back(m[i][b]);
        }
        if(a==c)return;
        for(int i=b-1;i>=d;i--){
            ans.push_back(m[c][i]);
        }
        if(b==d)return ;
        for(int i=c-1;i>a;i--){
            ans.push_back(m[i][d]);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> ans;
        int a= 0,b=n-1,c=m-1,d=0;
        while(a<= c && d<=b){
            once(ans,matrix,a,b,c,d);
            a++;d++;b--;c--;
        }
        return ans;
    }
};
