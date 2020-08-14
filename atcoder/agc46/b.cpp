#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e3 + 10;
const int maxm = 2e3 + 10;
const int inf = 1e9 + 9;
const int mod = 998244353;

ll dp[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    dp[a][b] = 1;
    for(int i = 1; i <= c; ++i){
        for(int j = 1; j <= d; ++j){
            if((i > a && j >= b) || (i >= a && j > b)){
                dp[i][j] = (i * dp[i][j - 1] + j * dp[i - 1][j] - dp[i - 1][j - 1] * (i - 1) % mod * (j - 1) % mod + mod) % mod;
            }
        }
    }
    cout << dp[c][d] << '\n';
    return 0;
}
