class Solution {
public:
    string convertToTitle(int n) {
        if(n==1)return "A";
        string ans;
        while(n){
            n--;
            int t=n%26;
            ans+='A'+t;
            n/=26;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
