class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        sort(strs.begin(),strs.end());
        string temp = strs[0];
        for(int j=0;j<temp.size();j++){
            for(int i=0;i<strs.size();i++){
                if(temp[j]!=strs[i][j]) return temp.substr(0,j);
            }
        }
        return temp;
    }
};

//O(n^2)
