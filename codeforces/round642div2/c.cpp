#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 15;

ll func(ll base, ll len){
    return len * (base + base + len - 1) / 2;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for(int bb = b; bb <= c; ++bb){
        ll x1 = bb + a, y1 = bb + b;
        ll x2 = c, y2 = d;
        x1 = max(x1, x2);
        if(x1 > y2){
            ans += 1LL * (y1 - x1 + 1) * (y2 - x2 + 1);
        }
        else if(y1 <= x2)continue;
        else if(y1 <= y2){
            ll base = x1 - x2, len = y1 - x1 + 1;
            ans += func(base, len);
            //cout << bb << ' ' << base << ' ' << len << ' ' << func(base, len) << '\n';
        }
        else{
            ll base = x1 - x2, len = y2 - x1 + 1;
            ans += func(base, len);
            ans += 1LL * (y1 - y2) * (y2 - x2 + 1);
        }
    }
    cout << ans << '\n';
    return 0;
}
