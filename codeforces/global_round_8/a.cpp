#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;
const ll inf = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    while(t--){
        int ans = 0, a, b, n;
        cin >> a >> b >> n;
        while(a <= n && b <= n){
            if(a > b)b += a;
            else a += b;
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
