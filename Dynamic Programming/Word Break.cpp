//method 1
class Solution {
public:
    bool recursive(string s, vector<string> &wordDict){
        if(s.size()==0) return true;
        for(int i=0;i<s.size();i++){
            string k = s.substr(0,i+1);
            if(find(wordDict.begin(),wordDict.end(),k)!=wordDict.end()){
                string rem = s.substr(i+1,s.size());
                if(recursive(rem,wordDict)) return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return recursive(s,wordDict);
    }
};

//method 2
class Solution {
public:
    bool recursive(int ind,string s, vector<string> &wordDict,vector<int> &dp){
        if(s.size()==ind) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<s.size();i++){
            string k = s.substr(ind,i-ind+1);
            if(find(wordDict.begin(),wordDict.end(),k)!=wordDict.end() && 
                 recursive(i+1,s,wordDict,dp)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        return recursive(0,s,wordDict,dp);      
    }
};

//method 3
class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,0);
        set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        dp[n]=1;
        for(int ind = n-1; ind >= 0; ind--) {
            for(int i = ind; i < s.length(); i++) {
                string cur = s.substr(ind, i-ind+1);
                if(dict.find(cur) != dict.end() && dp[i+1]) {
                    dp[ind] = 1;
                    break;
                }
            }
        }
        return dp[0];      
    }
};
