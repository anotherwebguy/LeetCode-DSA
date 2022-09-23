//method 1
class Solution {
public:
    int fib(int n){
        if(n<=1) return n;
        return fib(n-1)+fib(n-2);
    }
    
    int climbStairs(int n) {
        return fib(n+1);
    }
};

//method 2
class Solution {
public: 
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int st[n+1];
        st[0]=0;
        st[1]=1;
        st[2]=2;
        for(int i=3;i<=n;i++){
            st[i]=st[i-1]+st[i-2];
        }
        return st[n];
    }
};
