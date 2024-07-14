class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int buy=0,sell=0;
        while(sell!=prices.size()){
            if(prices[buy]>prices[sell]){
                buy++;
                if(buy>sell){
                    sell=buy;
                }
            }else{
                ans=max(ans,prices[sell]-prices[buy]);
                sell++;
            }
        }
        return ans;
    }
};
