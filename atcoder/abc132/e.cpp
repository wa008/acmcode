// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;
int n,m;
bool vis[maxn][3];
vector<int> g[maxn];
int d[maxn][3];
priority_queue<pair<int, int>> qu;
int main()
{
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;i++){
        int a,b;scanf("%d%d",&a,&b);
        g[a].push_back(b);
    }
    int s,t;
    scanf("%d%d", &s, &t);
    qu.push(make_pair(0, s*3));
    int ans = -1;
    while(!qu.empty()){
        int dis = -qu.top().first, u = qu.top().second/3, ins = qu.top().second%3;qu.pop();
        if(u == t && ins == 0){
            ans = dis;
            break;
        }
        vis[u][ins] = 1;
        for(int v : g[u]){
            int nins = ins+1;
            int ndis = dis;
            if(nins==3){
                nins=0;
                ndis++;
            }
            if(!vis[v][nins]){
                vis[v][nins]=1;
                qu.push(make_pair(-ndis, v*3+nins));
            }
        }
    }
    printf("%d\n", ans);


    return 0;
}
