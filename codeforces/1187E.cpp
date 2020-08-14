#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+8;
typedef long long ll;

int n,m;
int ar[maxn];
vector<int> g[maxn];
int mx=0,root=0;
int d[maxn], sz[maxn];
ll ans=0;
void dfs1(int u,int pre){
    sz[u]=1;
    for(auto v: g[u]){
        if(v!=pre){
            dfs1(v,u);
            sz[u] += sz[v];
        }
    }
}
void dfs2(int u,int pre,ll s){
 //   cout<<u<<" "<<s<<"\n";
    ans = max(ans, s);
    for(auto v : g[u]){
        if(v!=pre){
            dfs2(v, u, s+n-sz[v]-sz[v]);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<n;i++)
    {
        int a,b;scanf("%d%d", &a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1, -1);
    ans = 0;
    for(int i=1;i<=n;i++)ans += sz[i];
    dfs2(1, -1, ans);
    printf("%lld\n", ans);



    return 0;
}
