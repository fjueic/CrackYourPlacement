class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int m=nums[0];
        for(int i=1;i<n;i++){
            if(i>m)return 0;
            if(m>=n-1)return 1;
            m=max(m,nums[i]+i);
        }
        return m>=n-1;
    }
};
