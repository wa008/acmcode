#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+9;
vector<int> g[maxn];
set<pair<int,int>> se;
int vis[maxn],n,m,cnt;
bool ff=1;
bool dfs3(int u,int pre,int x,int y){
    vis[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==pre || v==y)continue;
        if(v==x)return 1;
        if(!vis[v] && dfs3(v,u,x,y))return 1;
    }
    return 0;
}
bool chee(int x,int y){
    memset(vis, 0,sizeof(vis));
    return dfs3(x,-1,x,y);
}
int dd[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    //cout<<"m,m = "<<m<<endl;
    memset(dd,0,sizeof(dd));
    for(int i=1;i<=m;i++){
        int a,b;scanf("%d%d",&a,&b);
        assert(a!=b);
        g[a].push_back(b);
        g[b].push_back(a);
        dd[a]++;
        dd[b]++;
    }
    int ins=0;
    int a=0,b=0;
    int mark=0;
    for(int i=1;i<=n;i++){
        if(dd[i]&1){
            ff=0;
            mark=1;
        }
        if(dd[i]>=6)ins += maxn;
        else if(dd[i]==4){
            ins++;
            if(a==0)a=i;
            else if(b==0)b=i;
        }
    }
    if(ins<2){
        ff=0;
    }
    else if(ins==2 && ff){
        if(chee(a,b));
        else ff=0;
    }
    printf("%s\n",ff?"Yes":"No");
    return 0;
}
