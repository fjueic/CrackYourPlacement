class Solution {
public:
    string intToRoman(int num) {
        int nums[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string rom[] ={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string ans="";
        int i=12;
        while(num){
            if(num>=nums[i]){
                ans+=rom[i];
                num-=nums[i];
            }else{
                i--;
            }
        }
        return ans;
    }
};
