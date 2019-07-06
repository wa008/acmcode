#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9+7;
int n,m;
ll a[maxn];
map<ll,ll> ma;
int main()
{
    int p,k;
    scanf("%d%d%d", &n, &p, &k);
    for(int i=1;i<=n;i++)scanf("%lld", a+i);
    ll ans=0;
    for(int i=1;i<=n;i++){
        a[i] = a[i]*a[i]%p*a[i]%p*a[i]%p + p - k*a[i]%p;
        a[i] %= p;
        ans += ma[a[i]];
        ma[a[i]]++;
    }
    printf("%lld\n", ans);

    return 0;
}
