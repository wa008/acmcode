#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
const ll f = 1e6;
int n, m, k, q;
int ar[maxn];

int a[maxn], b[maxn], c[maxn], d[maxn];
ll ans = 0;
void dfs(int cnt, int last){
    if(cnt == n){
        ll tmp = 0;
        for(int i = 0; i < q; i++){
            if(ar[b[i]] - ar[a[i]] == c[i])tmp += d[i];
        }
        ans = max(ans, tmp);
    }
    else{
        for(int i = last; i <= m; i++){
            ar[cnt] = i;
            dfs(cnt + 1, i);
        }
    }
}
int main() 
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    ans = 0;
    cin >> n >> m >> q;
    for(int i = 0; i < q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    dfs(0, 1);
    cout << ans << '\n';

    return 0;
}
