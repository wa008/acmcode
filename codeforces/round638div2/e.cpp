#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e2 + 7;
const ll mod = 998244353;

ll n, k;
ll x[maxn], y[maxn];
bool dp[maxn][maxn];
int main() 
{
    cin >> n >> k;
    ll sa = 0, sb = 0, cnt = 0;
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        cin >> x[i] >> y[i];
        sa += x[i], sb += y[i];
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++ j){
            if(dp[i][j] == false)continue;
            //cout << "i, j = " << i << ' ' << j << '\n';
            //cout << k << ' ' << x[i + 1] << '\n';
            for(int in = 0; in < min(k, x[i + 1] + 1); ++in){
                //cout << i << ' ' << j << ' ' << in << '\n';
                if(y[i + 1] >= k - ((x[i + 1] - in) % k ) || (x[i + 1] - in) % k == 0){
                    dp[i + 1][(j + in) % k] |= dp[i][j];
                    //cout << "get : " << i + 1 << ' ' << (j + in) % k << '\n';
                }
            }
        }
    }
    for(int i = 0; i < k; ++i){
        if(dp[n][i]){
            ans = max(ans, (sa + sb - i) / k);
        }
    }
    cout << ans << "\n";

    return 0;
}
