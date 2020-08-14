#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const int mod = 998244353;
 
int dp[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    for(int i = 1; i < maxn; ++i){
        for(int j = 1; j < maxn; ++j){
            int x = 0, y = 0;
            if(i > 1)x = dp[i - 1][j];
            if(j > 1)y = dp[i][j - 1];
            dp[i][j] = max(x, y) + (__gcd(i, j) == 1);
        }
    }
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
    return 0;
}
