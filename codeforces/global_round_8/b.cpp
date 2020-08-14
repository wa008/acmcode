#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e3 + 10;
const int maxm = 2e3 + 10;
const int inf = 1e9 + 9;
const int mod = 998244353;

ll check(ll x){
    ll ans = 1;
    for(int i = 1; i <= 10 - x % 10; ++i)ans *= x / 10;
    for(int i = 1; i <= x % 10; ++i)ans *= x / 10 + 1;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    ll k;
    cin >> k;
    //for(int i = 0; i <= 10; ++i)cout << i << ' ' << check(i + 10) << '\n';
    ll l = 10, r = 1000;
    while(l < r){
        ll mid = (l + r) >> 1;
        if(check(mid) < k)l = mid + 1;
        else r = mid;
    }
    string out = "codeforces";
    for(int i = 0; i < l % 10; ++i){
        int cnt = l / 10 + 1;
        while(cnt--)cout << out[i];
    }
    for(int i = l % 10; i < 10; ++i){
        int cnt = l / 10;
        while(cnt--)cout << out[i];
    }
    cout << "\n";
    return 0;
}
