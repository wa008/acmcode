#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
int n, m, x;

ll ar[maxn], mid[maxn];
int main()
{
    int k, q;
    scanf("%d%d", &k, &q);
    for(int i=0;i<k;i++)scanf("%d", ar + i);
    while(q--){
        scanf("%d%d%d", &n, &x, &m);
        x %= m;
        ll s = 0;
        for(int i=0;i<k;i++){
            mid[i] = ar[i] % m;
            if(mid[i] == 0)mid[i] = m;
            s += mid[i];
        }
        ll a = s / m, b = s % m;
        a *= (n - 1) / k;
        a += b * ((n - 1) / k) / m;
        s = x + b * ((n - 1) / k) % m;
        //a += (n - 1) / k;
        for(int i=0;i<((n - 1) % k);i++)s += mid[i];
        a += s / m;
        printf("%lld\n", n - 1 - a);
    }
    return 0;
}
