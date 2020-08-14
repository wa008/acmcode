#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
const ll f = 1e6;
int n, m, k;

ll func(int a, int b, ll x){
    if(x == 0)return 0;
    if(a == b)return 0;
    if(x < a)return 0;
    ll ans = 0;
    ll cnt = b / __gcd(a, b);
    ans += x / a / cnt * a;
    ans += min(x % (cnt * a), 1LL * a - 1);
    //cout << a << ' ' << b << ' ' << x << ' ' << ans << '\n';
    return x - ans;
}

int main() 
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        int a, b, q;
        cin >> a >> b >> q;
        if(a < b)swap(a, b);
        vector<ll> ans;
        while(q--){
            ll l, r;
            cin >> l >> r;
            ans.push_back(func(a, b, r) - func(a, b, l - 1));
        }
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i == ans.size() - 1)cout << '\n';
            else cout << ' ';
        }
    }
    return 0;
}
