#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 7;
const ll mod = 998244353;

ll f[maxn], n, m, k;
ll my_pow(ll x, ll y){
    ll ans = 1;
    while(y > 0){
        if(y & 1)ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll C(int x, int y)
{
    if(y == 0 || y == x)return 1;
    return f[x] * my_pow(f[x - y], mod - 2) % mod * my_pow(f[y], mod - 2) % mod;
}
int main() 
{
    cin >> n >> m >> k;
    f[0] = 1;
    for(int i = 1; i < maxn; ++i)f[i] = f[i - 1] * i % mod;
    ll ans = 0;
    for(int i = 0; i <= k; i++){
        ll tmp = 1LL * m * C(n - 1, i) % mod * my_pow(m - 1, n - i - 1) % mod;
        //cout << m << ' ' << C(n - 1, i) << ' ' << my_pow(m - 1, n - i - 1) << '\n';
        //cout << i << ' ' << tmp << '\n';
        ans = (ans + tmp) % mod;
    }
    cout << ans << '\n';
    return 0;
}
