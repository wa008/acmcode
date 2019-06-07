#include<bits/stdc++.h>
#include<ctime>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const int maxm = 2e6+7;
const ll mod = 998244353 ;
int n,m,ar[maxn];
ll f[maxn];
vector<int> g[maxn];
ll ans = n;
void dfs(int u,int pre=-1){
    int sz = g[u].size();
    ans = ans*f[sz]%mod;
    for(int v : g[u]){
        if(v==pre)continue;
        dfs(v,u);
    }
}
int main()
{
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<n;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    f[0] = 1;
    for(int i=1;i<=n+2;i++)f[i] = f[i-1]*i%mod;
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}