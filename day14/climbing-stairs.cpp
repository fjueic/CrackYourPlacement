class Solution {
public:
    int climbStairs(int n) {
        long long i=0,j=1;
        while(n--+1){
            j+=i;
            i=j-i;
        }
        return i;
    }
};
