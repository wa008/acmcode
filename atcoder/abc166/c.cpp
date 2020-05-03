#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
const ll f = 1e6;
int n, m, k, q;
int ar[maxn];

vector<int> g[maxn];
int main() 
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)cin >> ar[i];
    for(int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int flag = 1;
        for(int v : g[i]){
            if(ar[i] <= ar[v]){
                flag = 0;
                break;
            }
        }
        ans += flag;
    }
    cout << ans << '\n';
    


    return 0;
}
