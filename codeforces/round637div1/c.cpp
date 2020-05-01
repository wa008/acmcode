#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
const ll f = 1e6;
int n, m, k;
int ar[maxn];

int dp[10007][1007];
bool vis[10007][1007];

int main() 
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    cin >> n >> m;
    for(int i = 1;i <= m; ++i)cin >> ar[i];
    sort(ar + 1, ar + m + 1);
    int g, r;
    cin >> g >> r;
    for(int i = 0; i <= m; ++i){
        for(int j = 0; j <= max(g, r); ++j)dp[i][j] = 1e9;
    }
    dp[0][0] = 0;
    int ans = 1e9;
    deque<pair<int , int> > qu;
    qu.push_back(make_pair(0, 0));
    while(qu.size() > 0){
        int x = qu.front().first, y = qu.front().second; qu.pop_front();
        if(y == 0 && n - ar[x] <= g){
            ans = min(ans, dp[x][y] * (g + r) + n - ar[x]);
            continue;
        }
        if(x < m){
            int v = y + ar[x + 1] - ar[x];
            if(v < g){
                if(!vis[x + 1][v]){
                    vis[x + 1][v] = 1;
                    dp[x + 1][v] = dp[x][y];
                    qu.push_front(make_pair(x + 1, v));
                }
            }
            else if(v == g){
                if(!vis[x + 1][0]){
                    vis[x + 1][0] = 1;
                    dp[x + 1][0] = dp[x][y] + 1;
                    qu.push_back(make_pair(x + 1, 0));
                }
            }
        }
        if(x > 1){
            int v = y + ar[x] - ar[x - 1];
            if(v < g){
                if(!vis[x - 1][v]){
                    vis[x - 1][v] = 1;
                    dp[x - 1][v] = dp[x][y];
                    qu.push_front(make_pair(x - 1, v));
                }
            }
            else if(v == g){
                if(!vis[x - 1][0]){
                    vis[x - 1][0] = 1;
                    dp[x - 1][0] = dp[x][y] + 1;
                    qu.push_back(make_pair(x - 1, 0));
                }
            }
        }
    }
    if(ans == 1e9)ans = -1;
    cout << ans << '\n';
    return 0;
}
