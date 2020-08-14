#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long ll;

int ar[maxn];
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int n, k, x;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> x;
        for(int i = 0; i < x; i++){
            int cnt;
            cin >> cnt;
            ar[cnt] = 1;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)ans += (ar[i] == 0);
    cout << ans << '\n';
    return 0;
}
