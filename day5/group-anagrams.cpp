class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<int,int> m;
        for(int i=0;i<strs.size();i++){
            string x= strs[i];
            sort(x.begin(),x.end());
            int t=hash<string>()(x);
            if(m.find(t)==m.end()){
                ans.push_back(vector<string>());
                m[t]=ans.size()-1;
            }
            ans[m[t]].push_back(strs[i]);
        }
        return ans;
    }
};
