class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(),z=0,t=n-1;
        for(int i=0;i<=t;){
            if(nums[i]==0){
                swap(nums[z],nums[i]);
                z++;i++;
            }else if(nums[i]==2){
                swap(nums[t],nums[i]);
                t--;
            }else{
                i++;
            }
        }
    }
};
