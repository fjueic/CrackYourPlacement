class Solution{
  public:
    int hash(string s){
        sort(s.begin(),s.end());
        int ans=0;
        int p=31;
        int t=p;
        for(char c:s){
            ans+=(c-'a'+1)*t;
            t*=p;
            ans%=(int)1e9+7;
        }
        return ans;
    }
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<int,vector<string>>m;
        for(string i:string_list){
            int t= hash(i);
            m[t].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
