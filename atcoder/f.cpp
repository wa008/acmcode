#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
int inf = 1e9 + 7;

vector<int> g[maxn];
int ans[maxn], ar[maxn], n;
int lis[maxn];

void dfs(int u, int p = -1)
{
    //cout << "u = " << u << '\n';
    int k = lower_bound(lis, lis + n, ar[u]) - lis;
    int pre_val = lis[k];
    lis[k] = ar[u];
    //for(int i = 0; i < 5; i ++)cout << lis[i] << ' '; cout << '\n';
    ans[u] = lower_bound(lis, lis + n, inf) - lis;
    for(int v : g[u]){
        if(v != p)dfs(v, u);
    }
    lis[k] = pre_val;
}

int main() 
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> ar[i];
    }
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(lis, 0x3f, sizeof(lis));
    inf = lis[0];
    dfs(1, -1);
    for(int i = 1; i <= n; i++)cout << ans[i] << '\n';
    return 0;
}
