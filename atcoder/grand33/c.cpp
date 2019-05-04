#include <bits/stdc++.h>
using namespace std;
#define y1 adfasfafa
const int maxn = 2e5+7;
typedef long long ll;

int n,m;
int ar[maxn];
vector<int> g[maxn];
int mx,root;
void dfs(int u,int pre,int dep){
    if(mx<dep){
        mx=dep;
        root=u;
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==pre)continue;
        dfs(v,u,dep+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    mx=-1;
    dfs(1,-1,0);
    mx=-1;
    dfs(root,-1,0);
    if(mx%3==1)printf("Second\n");
    else printf("First\n");

    return 0;
}
