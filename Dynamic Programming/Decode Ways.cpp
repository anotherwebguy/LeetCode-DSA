//method 1
class Solution {
public:
    int recursive(int i, string s){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        int ans = recursive(i+1,s);
        if(i<s.size()-1 && ((s[i]=='1') || (s[i]=='2' && s[i+1]<'7'))){
            ans += recursive(i+2,s);
        }
        return ans;
    }
    
    int numDecodings(string s) {
        return recursive(0,s);
    }
};

//method 2
class Solution {
public:
    int recursive(int i, string s,vector<int> &dp){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = recursive(i+1,s,dp);
        if(i<s.size()-1 && ((s[i]=='1') || (s[i]=='2' && s[i+1]<'7'))){
            ans += recursive(i+2,s,dp);
        }
        return dp[i]=ans;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return recursive(0,s,dp);
    }
};

//method 3
class Solution {
public:
    
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        if(s[0]=='0') return 0;
        dp[s.size()]=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='0') dp[i] = dp[i+1];
            if(i<s.size()-1 && ((s[i]=='1') || (s[i]=='2' && s[i+1]<'7'))){
                dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
};
