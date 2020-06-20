#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;
const ll inf = 1e9 + 7;

int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int n;
    cin >> n;
    ll ans = 1, res = 360;
    while(n != 0){
        ans *= res / n;
        n = res % n;
    }
    cout << ans << '\n';
    return 0;
}
