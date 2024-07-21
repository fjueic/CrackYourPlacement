class Solution {
public:

    string number(int num){
        string a[]={"","One", "Two", "Three", "Four", "Five", 
  "Six", "Seven", "Eight", "Nine", "Ten", 
  "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
  "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string b[]={"xxxx","xxxx", "Twenty", "Thirty", "Forty", "Fifty", 
  "Sixty", "Seventy", "Eighty", "Ninety"};
        if(num<20)return a[num];
        if(num/100!=0){
            return a[num/100]+" Hundred" + (num%100!=0?" ":"")+ number(num%100);
        }
        return b[num/10]+(num%10!=0?" ":"")+number(num%10);
    }
    string numberToWords(int num) {
        if(num==0)return "Zero";
        string ans="";
        if(num/1000000000!=0){
            ans+=number(num/1000000000)+" Billion";
            num%=1000000000;
            if(num!=0)ans+=" ";
        }if(num/1000000!=0){
            ans+=number(num/1000000)+" Million";
            num%=1000000;
            if(num!=0)ans+=" ";
        }if(num/1000!=0){
            ans+=number(num/1000)+" Thousand";
            num%=1000;
            if(num!=0)ans+=" ";
        }if(num!=0){
            ans+=number(num);
        }
        return ans;
    }
};
