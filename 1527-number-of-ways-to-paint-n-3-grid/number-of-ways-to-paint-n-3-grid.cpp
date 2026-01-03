class Solution {
public:
    int dp[5005][4][4][4];
    const int M = 1e9+7;
    int f(int n,int p,int fi,int s,int t){
        if(p==n) return 1;
        if(dp[p][fi+1][s+1][t+1]!=-1) return dp[p][fi+1][s+1][t+1];
        long long ans = 0;
        for(int i=0;i<3;i++){
            if(i==fi) continue;
            for(int j=0;j<3;j++){
                if(j==s or i==j) continue;
                for(int k=0;k<3;k++){
                    if(k==t or j==k) continue;
                    ans =(ans+ f(n,p+1,i,j,k))%M;
                }
            }
        }
        return dp[p][fi+1][s+1][t+1] = ans;
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n,0,-1,-1,-1);
    }
};