//dalao blog
//https://blog.csdn.net/qq564690377/article/details/16892027
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e2+7;
const ll mod = 1e9 + 9;
const int sz = 25;
#define afdafafafdafaf y1;
int n,m;
int ar[maxn];

ll dp[2][maxn][maxn];
pair<int, bool> p[maxn*2];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", &p[i].first);
        p[i].second = 1;
    }
    for(int i=n+1;i<=n+n;i++){
        scanf("%d", &p[i].first);
        p[i].second = 0;
    }
    int now = 0;
    sort(p+1, p+2*n+1);
    dp[0][0][0] = 1;
    int a = 0, b = 0;
    for(int i=1;i<=2*n;i++){
        int to = now ^ 1;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(dp[now][j][k] == 0)continue;
                int x = a - j - k;
                int y = b - j - k;
                dp[to][j][k] += dp[now][j][k];
                dp[to][j][k] %= mod;
                if(p[i].second == 1){
                    dp[to][j+1][k] += dp[now][j][k] * y;
                    dp[to][j+1][k] %= mod;
                }
                else{
                    dp[to][j][k+1] += dp[now][j][k] * x;
                    dp[to][j][k+1] %= mod;
                }
                dp[now][j][k] = 0;
            }
        }
        if(p[i].second == 1)a++;
        else b++;
        now ^= 1;
    }
    if((n-m) % 2 == 1){
        printf("0\n");
        return 0;
    }
    int x = (n - m) / 2 + m;
    int y = (n - m) / 2;
    printf("%lld\n", dp[now][x][y]);

    return 0;
}
