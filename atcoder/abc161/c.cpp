#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
int n, m, k;


int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    ll n, k;
    cin >> n >> k;
    ll ans = n;
    n = abs(n - k);
    ans = min(ans, n);
    n = n % k;
    ans = min(ans, n);
    n = abs(n - k);
    ans = min(ans, n);
    cout << ans << '\n';
    return 0;
}
