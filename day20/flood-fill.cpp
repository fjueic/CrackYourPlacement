class Solution {
public:
    void solve(vector<vector<int>> & image,int x,int y,int c,int curr){
        if( x<0 || y<0 || x>=image.size() || y>=image[0].size()||c==image[x][y] || curr!=image[x][y]){
            return;
        }
        image[x][y]=c;
        solve(image,x-1,y,c,curr);
        solve(image,x,y-1,c,curr);
        solve(image,x+1,y,c,curr);
        solve(image,x,y+1,c,curr);    
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans(image);
        solve(ans,sr,sc,color,image[sr][sc]);
        return ans;
    }
};
