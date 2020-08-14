#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;
const ll inf = 1e9 + 7;

ll func(ll &x, ll sq){
    ll l = 0, r = inf;
    while(l < r){
        ll mid = l + r + 1 >> 1;
        if(mid * (sq + sq + 2 * mid - 2) <= x * 2)l = mid;
        else r = mid - 1;
    }
    x -= l * (sq + sq + 2 * l - 2) / 2;
    return l;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        ll l, r;
        cin >> l >> r;
        int is_swap = 0;
        if(l < r){
            is_swap = 1;
            swap(l, r);
        }
        ll last = l - r;
        ll sq = sqrt(2 * last);
        if(sq * (sq + 1) > 2 * last)sq--;
        assert(sq * (sq + 1) <= 2 * last && (sq + 1) * (sq + 2) > 2 * last);
        l -= sq * (sq + 1) / 2;
        if(l == r && is_swap == 1)is_swap = 0;
        sq++;
        //cout << sq << ' ' << l << ' ' << r << ' ' << is_swap << '\n';
        ll len1 = func(l, sq);
        ll len2 = func(r, sq + 1);
        //cout << "len1, 2 = " << len1 << ' ' << len2 << '\n';
        ll n = max(sq + len1 * 2 - 2, sq + 1 + len2 * 2 - 2);
        if(is_swap == 1)swap(l, r);
        cout << "Case #" << cas << ": " << n << ' ' << l << ' ' << r << '\n';
    }
    return 0;
}
