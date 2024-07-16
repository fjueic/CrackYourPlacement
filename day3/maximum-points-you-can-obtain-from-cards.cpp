class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int a=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++)a+=cardPoints[i];
        if(k==n){
            return a;
        }
        int ans=a;
        for(int i=0;i<k;i++){
            a+=cardPoints[n-1-i]-cardPoints[k-i-1];
            ans=max(a,ans);
        }
        return ans;
    }
};
