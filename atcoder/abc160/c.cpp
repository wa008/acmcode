#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
int n, m, k;

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    cin >> m >> n;
    int pre = 0, ans = 0, fir = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(i > 0)ans = max(ans, x - pre);
        else fir = x;
        pre = x;
    }
    ans = max(ans, m - pre + fir);
    cout << m - ans << '\n';
    return 0;
}
