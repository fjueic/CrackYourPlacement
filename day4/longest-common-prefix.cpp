class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int a=strs[0].size();
        for(int i=1;i<strs.size();i++){
            if(a>strs[i].size())a=strs[i].size();
            int t;
            for(t=0;t<a;t++){
                if(strs[i][t]!=strs[0][t]){
                    break;
                }
            }
            a=t;
        }
        return strs[0].substr(0,a);
    }
};
