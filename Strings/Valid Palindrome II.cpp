class Solution {
public:
    bool helper(int lo, int hi, string s){
        while(lo<hi){
            if(s[lo]!=s[hi]) return false;
            lo++;
            hi--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int lo = 0, hi = s.size()-1;
        while(lo<hi){
            if(s[lo]!=s[hi]) break;
            lo++;
            hi--;
        }
        return helper(lo+1,hi,s) || helper(lo,hi-1,s);
    }
};
