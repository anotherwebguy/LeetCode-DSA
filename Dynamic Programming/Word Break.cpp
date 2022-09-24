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
