class Solution {
public:
    void merge(vector<int>&nums,int s,int m,int e){
        vector<int> t(e-s+1);
        int i=s,j=m+1,k=0;
        while(i<=m && j<=e){
            t[k++]=(nums[i]<nums[j]?nums[i++]:nums[j++]);
        }
        while(i<=m){
            t[k++]=nums[i++];
        }
        while(j<=e){
            t[k++]=nums[j++];
        }
        for(i=s;i<=e;i++){
            nums[i]=t[i-s];
        }
    }
    void mergesort(vector<int>&nums,int &ans,int s,int e){
        if(s>=e)return;
        int m=(s+e)/2;
        mergesort(nums,ans,s,m);
        mergesort(nums,ans,m+1,e);
        int i=s,j=m+1;
        while(i<=m && j<=e){
            if(nums[i]>2LL*nums[j]){
                ans+=m-i+1;
                j++;
            }else{
                i++;
            }
        }
        merge(nums,s,m,e);
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
        mergesort(nums,ans,0,nums.size()-1);
        return ans;
    }
};
