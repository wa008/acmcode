#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;

int n, m, k;

int ar[maxn], in[maxn];
int main() 
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", ar + i);
    }
    int pre = -1;
    ll ans = 1;
    for(int i=1;i<=n;i++){
        if(ar[i] >= n - m + 1){
            if(pre == -1){
                ans = 1;
            }
            else{
                ans = ans * (i - pre) % mod;
            }
            pre = i;
        }
    }
    printf("%lld ", 1LL * (n + n - m + 1) * m / 2);
    printf("%lld\n", ans);
    return 0;
}
