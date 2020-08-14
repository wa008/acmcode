#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9+7;
 
ll n,m,k;
ll ar[maxn];
 
int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    for(int i=1;i<=m;i++)scanf("%lld", ar+i);
    ll x = 1, ins=1, ans=0;
    while(ins<=m){
        x += (ar[ins]-x)/k*k;
        ll cnt = lower_bound(ar+ins, ar+m+1, x+k)-ar-ins;
        x += cnt;
        ins += cnt;
        assert(cnt>0);
        ans++;
    }
    printf("%lld\n", ans);
 
    return 0;
}