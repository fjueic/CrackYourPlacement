class Solution {
public:
    bool check(string h,string n,int t){
        for(int i=0;i<n.size();i++){
            int x=i+t-n.size()+1;
            if(h[x]!=n[i])return 0;
        }
        return 1;
    }
    int strStr(string haystack, string needle) {
        int hash=0;
        int roll=0;
        for(int i=0;i<needle.size();i++){
            hash+=needle[i]-'a'+1;
            roll+=haystack[i]-'a'+1;
        }
        roll-=haystack[needle.size()-1]-'a'+1;
        for(int i=needle.size()-1;i<haystack.size();i++){
            roll+=haystack[i]-'a'+1;
            if(hash==roll && check(haystack,needle,i))return i+1-needle.size();
            roll-=haystack[i+1-needle.size()]-'a'+1;
        }
        return -1;
    }
};
