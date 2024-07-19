class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
        int z=0;
        int zi=-1;
        long long int p=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                z++;
                zi=i;
            }else{
                p*=nums[i];
            }
        }
        vector<long long int> ans(n,0);
        if(z!=0){
            if(z==1)ans[zi]=p;
            return ans;
        }
        for(int i=0;i<n;i++){
            ans[i]=p/nums[i];
        }
        return ans;
    }
};
