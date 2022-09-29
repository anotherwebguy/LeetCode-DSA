//method 1 Tabulation
class Solution {
public:
    int isPal(int i,int j, string s, vector<vector<int>> &dp){
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]) return dp[i][j]=0;
        return dp[i][j] = isPal(i+1,j-1,s,dp);
    }
    
    int countSubstrings(string s) {
        int res=0;
        vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPal(i,j,s,dp)) res++;
            }
        }
        return res;
    }
};


//method 2 Iterative (Two Pointers
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans =0;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            //odd length palindromes
            while(l>=0 && r<n){
                if(s[l]==s[r]) ans++;
                else break;
                l--;
                r++;
            }
            if(i==0) continue;
            l=i-1,r=i;
            //even length palindromes
            while(l>=0 && r<n){
                if(s[l]==s[r]) ans++;
                else break;
                l--;
                r++;
            }
        }
        return ans;
    }
};
