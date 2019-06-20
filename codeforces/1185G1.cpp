#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int n,m;
int ar[maxn];
int a[maxn], b[maxn];
int dp[maxn][4];
int main()
{
    scanf("%d%d", &n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d", a+i, b+i);
    }
    dp[0][0]=1;
    for(int i=0;i<maxn;i++){
        for(int j=0;j<=3;j++){
            if(dp[i][j]==0)continue;
            for(int k=1;k<=n;k++){
                if(b[k]==j)continue;
                if((i&(1<<(k-1)))==0){
                    dp[i | (1<<(k-1))][b[k]] += dp[i][j];
                    dp[i | (1<<(k-1))][b[k]] %= mod;
                }
            }
        }
    }
    int t=0,ans=0;
    for(int i=0;i<maxn;i++){
        for(int j=0;j<=3;j++){
            t=0;
            for(int k=0;k<n;k++){
                if(i&(1<<k)){
                    t += a[k+1];
                }
            }
            if(t==m)ans = (ans+dp[i][j])%mod;
        }
    }
    printf("%d\n", ans);



    return 0;
}