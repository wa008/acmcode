#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> v;
        for(int i = 0; i < n; ++i){
            ll x;
            cin >> x;
            v.push_back(x);
        }
        vector<ll> a;
        ll mna = 0, mnb = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            ll now = 0, pre = 0;
            if(i - 2 >= 0){
                pre = a[i - 2];
            }
            if(i - 1 >= 0){
                if(i & 1){
                    now = pre + v[i] - v[i - 1];
                    mna = min(mna, now);
                    ans = max(ans, 1LL * (now - mna));
                }
                else{
                    now = pre - v[i] + v[i - 1];
                    mnb = min(mnb, now);
                    ans = max(ans, 1LL * (now - mnb));
                }
            }
            a.push_back(now);
            //cout << i << ' ' << v[i] << ' ' << a[i] << '\n';
        }
        for(int i = 0; i < n; i += 2)ans += v[i];
        cout << ans << '\n';
    }
    return 0;
}
