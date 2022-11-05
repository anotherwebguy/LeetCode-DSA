class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1,j=num2.size()-1;
        string res = "";
        int carry=0;
        while(i>=0 || j>=0){
            int sum=0;
            if(i>=0) sum+=num1[i]-'0';
            i--;
            if(j>=0) sum+=num2[j]-'0';
            j--;
            sum+=carry;
            res+=(sum%10)+'0';
            carry = sum/10;
        }
        if(carry) res+=carry+'0';
        reverse(res.begin(),res.end());
        return res;
    }
};

//O(n)
