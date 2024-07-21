class Solution {
public:
    string simplifyPath(string s) {
        int n=s.size();
        vector<string> t;
        for(int i=1;i<n;i++){
            string next;
            while(i!=n && s[i]!='/'){
                next+=s[i];
                i++;
            }
            if(next=="."){
                continue;
            }else if(next==".."){
                if(!t.empty())t.pop_back();
            }else if(!next.empty()){
                t.push_back(next);
            }
        }
        string ans="/";
        for(string str:t){
            ans+=str+"/";
        }
        if(!t.empty())ans.pop_back();
        return ans;
    }
};
