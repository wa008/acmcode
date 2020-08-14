#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 7;
const ll mod = 998244353;


int n, a, r, m;
vector<int> v;
ll func(ll len){
    ll x = 0, y = 0;
    for(int i = 0; i < n; ++i){
        if(v[i] < len){
            x += len - v[i];
        }
        else{
            y += v[i] - len;
        }
    }
    ll ans = 1LL * x * a + 1LL * y * r;
    if(m < a + r){
        ans -= 1LL * (a + r - m) * min(x, y);
    }
    return ans;
}
int main() 
{
    cin >> n >> a >> r >> m;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int l = v[0], r = v[n - 1];
    while(l < r){
        int mid = l + r >> 1;
        ll m1 = func(mid);
        ll m2 = func(mid + 1);
        if(m1 > m2)l = mid + 1;
        else r = mid;
        //cout << mid << ' ' << m1 << ' ' << m2 << '\n';
    }
    ll ans = func(l);
    //cout << "l = " << l << '\n';
    cout << ans << '\n';
    return 0;
}
