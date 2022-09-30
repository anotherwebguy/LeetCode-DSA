//method 1 recursion
class Solution {
public:
    void recursion(string s, string curr,vector<string> &wordDict, vector<string> &res){
        if(s.size()==0){
            res.push_back(curr);
        }
        for(int i=0;i<s.size();i++){
            string temp = s.substr(0,i+1);
            if(find(wordDict.begin(),wordDict.end(),temp)!=wordDict.end()){
                string rem = s.substr(i+1,s.size());
                if(curr!="") recursion(rem,curr+" "+temp,wordDict,res);
                else recursion(rem,curr+temp,wordDict,res);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        recursion(s,"",wordDict,res);
        return res;
    }
};
