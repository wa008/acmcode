#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+7;
const ll mod = 1e9+7;
int n,m;
vector<pair<int,int> > g[maxn];
vector<int> sz[maxn];
set<int>::iterator it;
int ins=0;
int a[3][maxn<<2],ans=0;
void dfs(int u,int pre,int root){
    if(g[u].size()==1)sz[u].push_back(u);
    int v1=0,v2=0;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i].first, val = g[u][i].second;
        if(v!=pre){
            dfs(v,u, root);
            for(auto x : sz[v])sz[u].push_back(x);
            if(v1==0){
                assert(sz[v].size()>0);
                v1 = sz[v][0];
            }
            else if(v2==0){
                assert(sz[v].size()>0);
                v2 = sz[v][0];
            }
        }
    }
    //cout<<v1<<" "<<v2<<"\n";
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i].first, val = g[u][i].second;
        if(v!=pre){
            int x1=0,x2=0,y1=0,y2=0,cnt=0;
            if(sz[v].size()==1){
                y1=y2=v;
            }
            else{
                y1 = sz[v][0];;
                y2 = sz[v].back();
                assert(y1!=y2);
            }
            if(sz[v].size()==ins-1){
                x1=x2=u;
                cnt++;
            }
            else{
                x1=root;
                if(v1==sz[v][0])x2 = v2;
                else x2=v1;
            }
            if(val==0)continue;
            assert(g[x1].size()==1);
            assert(g[x2].size()==1);
            assert(g[y1].size()==1);
            assert(g[y2].size()==1);
            ans++;
            a[0][ans] = x1;
            a[1][ans] = y1;
            a[2][ans] = val/2;
            if(a[0][ans]==a[1][ans])ans--;
            ans++;
            a[0][ans] = x2;
            a[1][ans] = y2;
            a[2][ans] = val/2;
            if(a[0][ans]==a[1][ans])ans--;
            ans++;
            a[0][ans] = x1;
            a[1][ans] = x2;
            a[2][ans] = -val/2;
            if(a[0][ans]==a[1][ans])ans--;
            ans++;
            a[0][ans] = y1;
            a[1][ans] = y2;
            a[2][ans] = -val/2;
            if(a[0][ans]==a[1][ans])ans--;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<n;i++){
        int a,b,c;scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()==2){
            printf("NO\n");
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()==1){
            ins++;
        }
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()==1){
            dfs(i, -1, i);
            break;
        }
    }
    printf("%s\n", "YES");
    printf("%d\n", ans);
    for(int i=1;i<=ans;i++)printf("%d %d %d\n", a[0][i], a[1][i], a[2][i]);
    return 0;
}