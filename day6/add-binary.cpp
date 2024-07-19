class Solution {
public:
    string addBinary(string a, string b) {
        int x=a.size();
        int y=b.size();
        if(x>y){
            b=string(x-y,'0')+b;
            y=x;
        } if(y>x){
            a=string(y-x,'0')+a;
            x=y;
        }
        char c='0';
        for(int i=x-1;i>=0;i--){
            if(a[i]=='1' && b[i]=='1'){
                a[i]=c;
                c='1';
            }else if(a[i]=='0' && b[i]=='0'){
                a[i]=c;
                c='0';
            }else if(c=='0'){
                a[i]='1';
            }else{
                a[i]='0';
            }
        }
        if(c=='0')return a;
        return "1"+a;
    }
};
