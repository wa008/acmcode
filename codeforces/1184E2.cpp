#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9+7;
 
int n,m;
int f[maxn];
struct node{
    int a,b,c,id;
    bool operator < (const node& n1)const{
        return c<n1.c;
    }
}no[maxn];
int findx(int x){
    return f[x]==x?x:f[x] = findx(f[x]);
}
int val[maxn];
vector<pair<int,int> > g[maxn];
int dfs_clock, st[maxn], pos[maxn], ta[maxn][21], dep[maxn];
 
void init(){
    dfs_clock=0;
    memset(st,0,sizeof(st));
    memset(pos,0,sizeof(pos));
    memset(ta,0,sizeof(ta));
    memset(dep,0,sizeof(dep));
    memset(val,0,sizeof(val));
}
int dfs_num=0;
void dfs(int u,int pre){
    dfs_num++;
    dep[u] = dep[pre] + 1;
    st[dfs_clock] = u;
    pos[u] = dfs_clock++;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i].first, val = g[u][i].second;
        assert(v!=pre);
        ta[dfs_clock-1][0] = val;;
        dfs(v,u);
        ta[dfs_clock-1][0] = val;;
        st[dfs_clock++] = u;
    }
}
void init_rmq(){
    for(int j=1;j<=20;j++){
        for(int i=0;i<dfs_clock;i++){
            if(i+(1<<j) > dfs_clock)break;
            ta[i][j] = max(ta[i][j-1], ta[i+(1<<(j-1))][j-1]);
        }
    }
}
int lca(int u,int v){
    if(pos[u]>pos[v])swap(u,v);
    u = pos[u];
    v = pos[v];
    int ins=0;
    while((1<<(ins+1))<=v-u)ins++;
    assert(u+(1<<ins) >= v-(1<<ins) && u+(1<<ins)<=v);
    //assert(ins<=20);
    ///cout<<u<<" "<<v<<" "<<ins<<endl;
    //cout<<u<<' '<<v<<"\n\n";
    return max(ta[u][ins], ta[v-(1<<ins)][ins]);
    /*
    assert(u+(1<<ins) >= v-(1<<ins)+1 && u+(1<<ins)-1<=v);
    if(dep[ta[u][ins]] < dep[ta[v-(1<<ins)+1][ins]])return ta[u][ins];
    else return ta[v-(1<<ins)+1][ins];*/
}
int ans[maxn];
bool vis[maxn];
int main()
{
    init();
    memset(vis,0,sizeof(vis));
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)f[i] = i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d", &no[i].a, &no[i].b, &no[i].c);
        no[i].id=i;
    }
    sort(no+1, no+m+1);
    int ins=0;
    for(int i=1;i<=m;i++){
        int a = no[i].a, b = no[i].b;
        //cout<<a << " " << b << "\n";
        a = findx(a);
        b = findx(b);
        if(a==b)continue;
        ins++;
        f[a] = b;
        g[b].push_back(make_pair(a, no[i].c));
        vis[i]=1;
        if(ins==n-1)break;
    }
    assert(ins==n-1);
    dfs(findx(1), 0);
    assert(dfs_clock<maxn/2);
    assert(dfs_num==n);
    /*
    for(int i=0;i<dfs_clock;i++)cout<<st[i]<<" ";cout<<"\n";
    for(int i=0;i<dfs_clock;i++)cout<<ta[i][0]<<" ";cout<<"\n";
    for(int i=1;i<=n;i++)cout<<dep[i]<<" ";cout<<"\n";
    for(int i=1;i<=n;i++)cout<<pos[i]<<" ";cout<<"\n";
    for(int i=1;i<=n;i++)cout<<val[i] << " ";cout<<"\n";*/
    init_rmq();
    memset(ans, -1, sizeof(ans));
    for(int i=1;i<=m;i++){
        if(vis[i])continue;
        int a = no[i].a, b = no[i].b;
        int x = lca(a,b);
        //cout<<a<<" "<<b<<" "<<x<<"\n";
        ans[no[i].id] = x;
    }
    for(int i=1;i<=m;i++){
        if(ans[i]!=-1)printf("%d\n", ans[i]);
    }
    return 0;
}