#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2 + 10;
const int maxm = 2e3 + 10;
const int inf = 1e9 + 9;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    if(abs(a - b) <= t * v - t * w)cout << "YES\n";
    else{
        cout << "NO\n";
    } 

    return 0;
}
