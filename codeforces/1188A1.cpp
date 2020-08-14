#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1e9+7;
int n,m;
vector<int> g[maxn];
int sz[maxn],flag=1,ins=0;
void dfs(int u,int pre){
    if(g[u].size()==1)sz[u] = 1;
    else sz[u] = 0;
    for(int v:g[u]){
        if(v!=pre){
            dfs(v,u);
            sz[u] += sz[v];
            if(sz[v]==1 && g[v].size()!=1){
                //cout<<"v = "<<v<<"\n";
                flag=0;
            }
            if(sz[v]==ins-1 && g[u].size()!=1){
                //cout<<"u = "<<u<<"\n";
                flag=0;
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()==1 || g[i].size()>=3){
            ins++;
        }
        else{
            flag=0;
        }
    }
    //dfs(1, -1);
    printf("%s\n", flag==1?"YES":"NO");
    
    return 0;
}