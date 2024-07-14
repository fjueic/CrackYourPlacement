class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write=0,read=0;
        while(read!=nums.size()){
            nums[write]=nums[read];
            while(read!=nums.size() && nums[read]==nums[write]){
                read++;
            }
            write++;
        }
        return write;
    }
};
