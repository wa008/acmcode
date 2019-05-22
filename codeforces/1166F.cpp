#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;
int ar[maxn];

vector<pair<int, int>> g[maxn];
set<int> se[maxn];
map<int,int> ma[maxn];
int c,p;
int f[maxn];
int findx(int u){
    return f[u]==u?u:f[u] = findx(f[u]);
}
void un(int x,int y){
    x = findx(x);
    y = findx(y);
    if(x==y)return ;
    if(se[x].size()>se[y].size())swap(x,y);
    for(auto it : se[x])se[y].insert(it);
    se[x].clear();
    //cout<<"un, x, y  = "<<x<<" "<<y<<"\n";
    //for(auto it : se[y])cout<< it << ' '; cout << "\n";
    f[x]=y;
}
void dfs(int u,int py,int pz){
    //cout<<"u = "<<u<<"\n";
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].first, c=g[u][i].second;
        //cout<<v<<" "<<c<<" "<<py << " " << pz <<"\n";
        if(pz==c){
            un(py, v);
        }
    }
}
void add(int a,int b,int c){
    dfs(a,b,c);
    dfs(b,a,c);
    if(ma[a].count(c)) un(ma[a][c], b);
    else ma[a][c] = b;
    if(ma[b].count(c)) un(ma[b][c], a);
    else ma[b][c] = a;
    se[findx(a)].insert(b);
    se[findx(b)].insert(a);
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&c,&p);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    while(p--){
        char ch[2];
        scanf("%s",ch);
        int x,y,z;
        if(ch[0]=='+'){
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
        }
        else{
            scanf("%d%d",&x,&y);
            x = findx(x);
            //cout<<"x,y = "<<x<<" "<<y<<"\n";
            if(x==findx(y) || se[x].count(y))printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}
