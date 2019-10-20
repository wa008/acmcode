#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;
const ll mod = 1e9 + 9;
#define afdafafafdafaf y1;
int ar[maxn], n;

struct node{
    ll a[4][4];
}no[maxn];
int arr[4][maxn];
vector<int> g[maxn];
node dfs(int u, int pre){
    node nou;
    memset(nou.a, 0, sizeof(nou.a));
    for(int v : g[u]){
        if(v == pre)continue;
        node mid = dfs(v, u);
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(i != j)nou.a[i][j] += mid.a[i][j];
            }
        }
    }
    memset(no[u].a, 0, sizeof(no[u].a));
    no[u].a[1][2] = arr[1][u] + nou.a[2][3];
    no[u].a[1][3] = arr[1][u] + nou.a[3][2];
    no[u].a[2][1] = arr[2][u] + nou.a[1][3];
    no[u].a[2][3] = arr[2][u] + nou.a[3][1];
    no[u].a[3][1] = arr[3][u] + nou.a[1][2];
    no[u].a[3][2] = arr[3][u] + nou.a[2][1];
    return no[u];
}
int in[maxn], av[maxn];
void dfs2(int u, int pre, int col, ll val, int pre_col){
    av[u] = col;
    if(in[u] == 1 && pre != 0){
        //assert(val == arr[col][u]);
    }
    for(int v : g[u]){
        if(v==pre)continue;
        ll mn = 1e18;
        int ins = 0;
        for(int j=1;j<=3;j++){
            if(col != j){
                if(mn > no[u].a[col][j] && j != pre_col){
                    mn = no[u].a[col][j];
                    ins = j;
                }
            }
        }
        //assert(val == mn);
        dfs2(v, u, ins, val - arr[col][u], col);
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++)scanf("%d", &arr[i][j]);
    }
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        in[a]++;
        in[b]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i] >= 3){
            printf("-1\n");
            return 0;
        }
    }
    int be = 0;
    int xx = 0;
    for(int i=1;i<=n;i++){
        if(in[i] == 1){
            be = i;
            xx++;
        }
        else{
            assert(in[i] == 2);
        }
    }
    assert(xx == 2);
    node mid = dfs(be, 0);
    ll ans = 1e18, ins = 0;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(i != j){
                if(ans >= mid.a[i][j]){
                    ans = mid.a[i][j];
                    ins = i;
                }
            }
        }
    }
    dfs2(be, 0, ins, ans, -1);
    printf("%lld\n", ans);
    for(int i=1;i<=n;i++)printf("%d%c", av[i], i==n ? '\n' : ' ');

    return 0;
}
