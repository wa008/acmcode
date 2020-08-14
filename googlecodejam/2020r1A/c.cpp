#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
const ll f = 1e6;
int n, m, k;

ll func(int x, int y){
    return x * f + y;
}

int main() 
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    //cout << "t = " << t << '\n';
    vector<ll> s[2];
    for(int cas = 1; cas <= t; cas++){
        int n, m;
        cin >> n >> m;
        cout << "Case #" << cas << ": ";
        //cout << n << ' ' << m << '\n';
        vector<int> g[n + 2];
        vector<int> vis[n + 2], in[n + 2];
        vector<ll> dir[n + 2][m + 2];
        ll ans = 0, base = 0;
        int ins = 0;
        vis[0].resize(m + 1);
        vis[n + 1].resize(m + 1);
        in[0].resize(m + 1);
        in[n + 1].resize(m + 1);
        g[0].resize(m + 2);
        g[n + 1].resize(m + 2);
        for(int i = 0; i <= n + 1; i++){
            dir[i][0].resize(4);
            dir[i][m + 1].resize(4);
        }
        for(int j = 0; j <= m + 1; j++){
            dir[0][j].resize(4);
            dir[n + 1][j].resize(4);
        }
        for(int i=1;i<=n;i++){
            g[i].resize(m + 2);
            vis[i].resize(m + 2);
            in[i].resize(m + 2);
            for(int j=1;j<=m;j++){
                vis[i][j] = 0;
                in[i][j] = 0;
                int x;
                cin >> x;
                g[i][j] = x;
                base += x;
                dir[i][j].resize(4);
                dir[i][j][0] = func(i - 1, j);
                dir[i][j][1] = func(i + 1, j);
                dir[i][j][2] = func(i, j - 1);
                dir[i][j][3] = func(i, j + 1);
                s[0].push_back(func(i, j));
            }
        }
        /*
           for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++)cout << g[i][j] << ' ';
           cout << '\n';
           }
           */
        vector<ll> mv;
        vector<ll> del;
        int index = 0;
        for(; ;){
            //cout << "in = " << ++index << "\n";
            del.resize(0);
            ans += base;
            if(s[ins].size() == 0)break;
            int ans_ins = 0;
            for(ll div : s[ins]){
                mv.resize(0);
                int x = div / f, y = div % f;
                //cout << "x, y = " << x << ' ' << y << '\n';
                if(vis[x][y])continue;
                for(int k = 0; k < 4;k++){
                    ll mid = dir[x][y][k];
                    int r = mid / f, c = mid % f;
                    //cout << x << ' ' << y << ' ' << r << ' ' << c << '\n';
                    if(r >= 1 && r <= n && c >= 1 && c <= m){
                        //assert(vis[r][c] == 0);
                        mv.push_back(g[r][c]);
                    }
                }
                ll sum = 0;
                for(ll in : mv)sum += in;
                if(g[x][y] * int(mv.size()) < sum){
                    //cout << "delete x, y = " << x << ' ' << y << '\n';
                    //cout << "size = " << mv.size() << '\n';
                    //for(ll x : mv) cout << x / f << ' ' << x % f << '\n';
                    base -= g[x][y];
                    vis[x][y] = 1;
                    ans_ins = 1;
                    del.push_back(div);
                    for(int k = 0; k < 4;k++){
                        ll mid = dir[x][y][k];
                        int r = mid / f, c = mid % f;
                        //cout << x << ' ' << y << ' ' << r << ' ' << c << '\n';
                        if(r >= 1 && r <= n && c >= 1 && c <= m){
                            if(in[r][c] == 0){
                                s[ins ^ 1].push_back(mid);
                                in[r][c] = 1;
                            }
                        }
                    }
                }
                //cout << "x, y = " << x << ' ' << y << '\n';
            }
            s[ins].resize(0);
            ins ^= 1;
            for(ll div : s[ins]){
                int x = div / f, y = div % f;
                in[x][y] = 0;
            }
            for(ll div : del){
                int x = div / f, y = div % f;
                int x1 = dir[x][y][0] / f, y1 = dir[x][y][0] % f;
                int x2 = dir[x][y][1] / f, y2 = dir[x][y][1] % f;
                //cout << "x12 y12 = " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
                dir[x1][y1][1] = func(x2, y2);
                dir[x2][y2][0] = func(x1, y1);

                //cout << "x, y = " << x << ' ' << y << '\n';
                x1 = dir[x][y][2] / f, y1 = dir[x][y][2] % f;
                x2 = dir[x][y][3] / f, y2 = dir[x][y][3] % f;
                dir[x1][y1][3] = func(x2, y2);
                dir[x2][y2][2] = func(x1, y1);
                //cout << "x, y = " << x << ' ' << y << '\n';
            }
            /*
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)assert(in[i][j] == 0);
            }
               for(int i=1;i<=n;i++){
               for(int j=1;j<=m;j++)cout << vis[i][j] << ' ';
               cout << '\n';
               }
               */
            if(ans_ins == 0)break;
        }
        cout << ans << '\n';
    }
    return 0;
}
