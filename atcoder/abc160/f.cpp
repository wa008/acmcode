#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int mod = 1e9+7;
typedef long long ll;
int n,m;

ll f[maxn], inv[maxn], sinv[maxn];
vector<int> g[maxn];
int s[maxn];
void dfs(int u, int p){
    s[u] = 1;
    for(int v : g[u]){
        if(v != p){
            dfs(v, u);
            s[u] += s[v];
        }
    }
}
ll ans[maxn];
void dfs2(int u, int p){
    for(int v : g[u]){
        if(v != p){
            ans[v] = ans[u] * s[v] % mod * inv[n - s[v]] % mod;
            dfs2(v, u);
        }
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    inv[0] = inv[1] = sinv[0] = 1;
    f[0] = 1;
    for(int i=2;i<maxn;i++)inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    for(int i=1;i<maxn;i++)sinv[i] = sinv[i - 1] * inv[i] % mod, f[i] = f[i-1] * i % mod;
    ll res = f[n];
    for(int i=1;i<=n;i++){
        res = res * inv[s[i]] % mod;
    }
    ans[1] = res;
    dfs2(1, 0);
    for(int i=1;i<=n;i++)cout << ans[i] << "\n";
    return 0;
}
