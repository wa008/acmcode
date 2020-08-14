#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9+7;

int n,m;
int ar[maxn];
vector<int> g[maxn];
ll ans=1;
ll dp[maxn];
void dfs(int u,int pre){
    int ins = (u!=1)+1;
    for(auto v:g[u]){
        if(v!=pre){
            if(m<=ins)ans=0;
            ans = ans*(m-ins)%mod;
            //cout<<v<<" "<<m-ins<<"\n";
            ins++;
            dfs(v, u);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<n; i++){
        int a,b;scanf("%d%d", &a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans=m;
    dfs(1, 0);
    printf("%lld\n", ans);

    return 0;
}
