class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m=nums[0];
        int t=1;
        for(int i=1;i<nums.size();i++){
            if(t==0 && nums[i]!=m){
                t=1;
                m=nums[i];
                continue;
            }
            if(m==nums[i])t++;
            else t--;
        }

        return m;
    }
};
