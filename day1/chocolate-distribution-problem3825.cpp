class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        long long ans=INT_MAX;
        for(int i=0;i<n-m+1;i++){
            long long t=a[i+m-1]-a[i];
            if(t<ans)ans=t;
        }return ans;
    }   
};
