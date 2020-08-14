#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int n;
vector<int> g[maxn];
int f[maxn],d[maxn],root,mx=-1;
int flag;
int dd[maxn];
void dfs(int u,int pre,int dep){
    f[u] = pre;
    if(mx<dep){
        mx=dep;
        root=u;
    }
    if(dd[dep]==-1)dd[dep] = g[u].size();
    else if(dd[dep]!=g[u].size()){
        flag=0;
    }
    for(int v: g[u]){
        if(v!=pre){
            dfs(v,u,dep+1);
        }
    }
}
bool che(int x){
    memset(dd,-1,sizeof(dd));
    flag=1;
    mx=-1;
    dfs(x, -1, 0);
    return flag;
}
set<int> s[maxn];
void dfs2(int u,int pre, int dep){
    for(int v:g[u]){
        if(v!=pre && g[v].size()<=2){
            dfs2(v,u, dep+1);
        }
    }
    if(g[u].size()==1)s[dep].insert(u);
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n==1){
        printf("1\n");
        return 0;
    }
    mx=-1;
    dfs(1, -1, 0);
    mx=-1;
    dfs(root, -1, 0);
    int ins=mx/2;
    while(ins>0){
        ins--;
        root = f[root];
    }
    //if(n==99998)cout<<"root = "<<root<<endl;
    //cout<<"root = "<<root<<"\n";
    dfs2(root, -1, 0);
    for(int i=0;i<maxn;i++)if(s[i].size()==1){
        root = *s[i].begin();
    }
    int now = root;
    if(che(now)){
        printf("%d\n", now);
    }
    else printf("-1\n");
    //if(n==99998)cout<<"now = "<<now<<endl;
    //if(n==99998)cout<<"mx = "<<mx<<endl;
    return 0;
}