class Solution {
  public:
    void solve(vector<vector<int>> &ans,vector<int> &arr,int i,int n){
        if(i==n){
            ans.push_back(arr);
        }
        set<int>s;
        for(int j=i;j<n;j++){
            if(s.find(arr[j])!=s.end())continue;
            s.insert(arr[j]);
            swap(arr[i],arr[j]);
            solve(ans,arr,i+1,n);
            swap(arr[i],arr[j]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        solve(ans,arr,0,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
