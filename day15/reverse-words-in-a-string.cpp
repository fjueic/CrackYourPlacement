class Solution {
public:
    void reverse(string &s ,int i,int j){
        int n=j-i+1;
        for(int x=0;x<n/2;x++){
            swap(s[x+i],s[n-x-1+i]);
        }
    }
    string reverseWords(string s) {
        while(0<s.size() && s[0]==' '){
            s.erase(0,1);
        }
        int n=s.size();
        for(int i=0;i<n/2;i++){
            swap(s[i],s[n-i-1]);
        }
        int i=0;
        while(i<s.size()){
            if(i!=0)i++;
            while(i<s.size() && s[i]==' '){
                s.erase(i,1);
            }
            int j=i;
            while(j<s.size() && s[j]!=' '){
                j++;
            }
            j--;
            reverse(s,i,j);
            i=j+1;
        }
        return s;
    }
};
