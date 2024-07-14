class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r=0,w=0,n=nums.size();
        while(r!=n){
            if(nums[w]!=0){
                w++;
                if(w>r){
                    r=w;
                }
                continue;
            }
            if(nums[r]!=0){
                swap(nums[r],nums[w]);
                w++;
            }
            r++;
        }
    }
};
