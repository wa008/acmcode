#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
typedef long long ll;
const int maxn = 1e5+7;

vector<int> g[maxn];
int n,m;
bool vis[maxn];
set<int> se;
void dfs(int u,int pre){
    se.insert(u);
    vis[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!vis[v] && pre!=v){
            dfs(v,u);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(!c){
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    ll ans=1;
    for(int i=1;i<=m;i++){
        ans = ans*n%mod;
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            se.clear();
            dfs(i,-1);
            ll ins = 1, x = se.size();
            for(int i=1;i<=m;i++){
                ins = ins*x%mod;
            }
            //cout<<"ins = "<<ins<<endl;
            ans = (ans+mod-ins)%mod;
        }
    }
    printf("%lld\n",ans);

    return 0;
}
