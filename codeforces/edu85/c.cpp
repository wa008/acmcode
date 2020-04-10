#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
int n, m, k;


int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    vector<ll> a, b;
    while(t--){
        cin >> n;
        a.resize(0);
        b.resize(0);
        for(int i = 0; i < n; i++){
            ll x, y;
            cin >> x >> y;
            a.push_back(x);
            b.push_back(y);
        }
        a.push_back(a[0]);
        b.push_back(b[0]);
        ll base = 0, ans = a[0];
        for(int i=1;i<=n;i++){
            if(b[i - 1] >= a[i]);
            else base += a[i] - b[i - 1];
        }
        for(int i = 1; i <= n; i++){
            if(b[i - 1] >= a[i])ans = min(ans, a[i]);
            else ans = min(ans, b[i - 1]);
        }
        cout << ans + base << '\n';
    }
    return 0;
}
