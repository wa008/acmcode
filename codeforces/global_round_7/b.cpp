#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
int n, m, k;

ll a[maxn], b[maxn], x[maxn];
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n;i++)scanf("%lld", b + i);
    ll mx = 0;
    for(int i=1;i<=n;i++){
        mx = max(mx, a[i-1]);
        x[i] = mx;
        a[i] = x[i] + b[i];
    }
    for(int i=1;i<=n;i++)printf("%lld%c", a[i], i == n ? '\n' : ' ');



    return 0;
}
