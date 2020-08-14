#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e1+7;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    vector<ll> v;
    for(int cas = 1; cas <= t; cas++){
        ll n, d;
        cin >> n >> d;
        v.resize(0);
        for(int i=0;i<n;i++){
            ll x;
            cin >> x;
            v.push_back(x);
        }
        ll ans = d;
        for(int i = v.size() - 1; i >= 0; i--){
            ll x = v[i];
            ans = ans / x * x;
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }
    return 0;
}
