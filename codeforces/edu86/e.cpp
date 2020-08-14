#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
const ll mod = 998244353;
ll qpow(ll x, ll y){
    ll ans = 1;
    while(y > 0){
        if(y & 1)ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
ll f[maxn];
ll C(int x, int y){
    if(x == y || y == 0)return 1;
    return f[x] * qpow(f[y], mod - 2) % mod * qpow(f[x - y], mod - 2) % mod;
}

int main() 
{
    int k, n;
    f[0] = 1;
    cin >> n >> k;
    if(k >= n){
        cout << "0\n";
        return 0;
    }
    for(int i = 1; i <= n; ++ i)f[i] = f[i - 1] * i % mod;
    ll ans = 0;
    int r = n - k;
    int sufx = 1;
    for(int i = 0; i <= r; ++ i){
        ans += mod + sufx * C(r, i) * qpow(r - i, n);
        ans %= mod;
        sufx *= -1;
    }
    ans = ans * C(n, r) % mod;
    if(k != 0)ans = ans * 2 % mod;
    cout << ans << '\n';
    return 0;
}
