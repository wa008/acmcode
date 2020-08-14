#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9 + 9;
#define afdafafafdafaf y1;
int ar[maxn];

struct edge
{
    int to,next,w;
}a[maxn<<1];
int n,m,k,head[maxn],cnt;
int root,sum,sz[maxn], f[maxn], vis[maxn];
void addedge(int u,int v,int w)
{
    a[++cnt].to=v;
    a[cnt].next=head[u];
    a[cnt].w=w;
    head[u]=cnt;
}
pair<ll, ll> cal(int u, int pre){
    vector<ll> v1, v2;
    ll sa = 0, sb = 0;
    for(int e = head[u]; e; e = a[e].next){
        int v = a[e].to;
        if(v == pre)continue;
        pair<ll,ll> mid = cal(v, u);
        v2.push_back(mid.first - mid.second + a[e].w);
        sb += mid.second;
    }
    sa = sb;
    sort(v2.begin(), v2.end());
    for(int i=0;i<k;i++){
        if(i>=v2.size())break;
        if(v2[v2.size() - 1 - i] < 0)break;
        if(i<k-1)sa += v2[v2.size() - 1 - i];
        sb += v2[v2.size() - 1 - i];
    }
    return make_pair(sa, sb);
}

int main()
{
    int t;scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        for(int i=0;i<=n;i++)head[i] = vis[i] = 0;
        f[0] = n;
        cnt = 0;
        for(int i=1;i<n;++i){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u,v,w);
            addedge(v,u,w);
            //cout << u << ' ' << v << ' ' << w << '\n';
        }
        sz[1] = n;
        pair<ll,ll> ans = cal(1, 0);
        printf("%lld\n", ans.second);
    }
    return 0;
}
