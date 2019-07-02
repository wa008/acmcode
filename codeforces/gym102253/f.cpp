#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
const int mod = 1e9+7;
typedef long long ll;
int n,m;
int nex[maxn],vis[maxn];
int la[maxn], lb[maxn], a[maxn], b[maxn];
int main()
{
    int cas=0;
    while(scanf("%d%d", &n, &m)==2){
        for(int i=0;i<=max(n,m);i++)la[i] = lb[i] = 0;
        for(int i=0; i<n; i++){
            scanf("%d", a+i);
        }
        for(int i=0;i<=n;i++)vis[i] = la[i] = 0;
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            int x = i, cnt = 0;
            while(!vis[x]){
                vis[x] = 1;
                cnt++;
                x = a[x];
            }
            la[cnt]++;
        }
        for(int i=0; i<m; i++){
            scanf("%d", b+i);
        }
        for(int i=0;i<=m;i++)vis[i] = lb[i] = 0;
        for(int i=0;i<m;i++){
            if(vis[i])continue;
            int x = i, cnt = 0;
            while(!vis[x]){
                vis[x] = 1;
                cnt++;
                x = b[x];
            }
            lb[cnt]++;
        }
        ll ans=1;
        for(int i=1;i<=n;i++){
            ll res=0;
            for(int j=1; j*j<=i; j++){
                if(i%j==0){
                    int k = j;
                    res += lb[k]*k;
                    if(j*j!=i){
                        k = i/j;
                        res += lb[k]*k;
                    }
                }
            }
            int ins = la[i];;
            while(ins--){
                ans = ans * res % mod;
            }
        }
        printf("Case #%d: %lld\n",++cas, ans);
    }
    return 0;
}
