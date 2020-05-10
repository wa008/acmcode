#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 15;

int c[maxn], a[maxn][maxn], mid[maxn];
int n, m, x;
int main() 
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    cin >> n >> m >> x;
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    int ans = -1;
    for(int i = 0; i < (1 << n); ++i){
        int cnt = 0, ins = i;
        memset(mid, 0, sizeof(mid));
        for(int j = 0; j < n; ++j){
            if(ins & (1 << j)){
                for(int k = 0; k < m; ++k){
                    mid[k] += a[j][k];
                }
                cnt += c[j];
            }
        }
        int flag = 1;
        for(int k = 0; k < m; ++k)if(mid[k] < x)flag = 0;
        if(flag == 1){
            if(ans == -1 || ans > cnt)ans = cnt;
        }
    }
    cout << ans << "\n";
    return 0;
}
