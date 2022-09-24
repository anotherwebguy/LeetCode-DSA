class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> v(n+1,false);
        v[1]=false;
        v[2]=true;
        for(int i=3;i<n+1;i++)
        {
            for(int j=1;j<3;j++)
            {
                if(i%j==0)
                {
                    if(v[i-j]==false)
                        v[i]=true;
                }
            }
        }
        return v[n];
    }
};
