#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e4 + 300;
const ll inf = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ans = inf;
        for(int i = 1; i <= n; ++i){
            int x, y;
            cin >> x >> y;
            ans = min(ans, (m + x - 1) / x * y);
        }
        cout << ans << '\n';
    }
    return 0;
}
