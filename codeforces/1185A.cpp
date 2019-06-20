#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

ll n,m;
ll ar[maxn];

int main()
{
    for(int i=0;i<3;i++)scanf("%lld", ar+i);
    sort(ar, ar+3);
    scanf("%lld",&n);
    ll ans=0;
    ans += max(0LL, n-(ar[1]-ar[0]));
    ans += max(0LL, n-(ar[2]-ar[1]));
    printf("%lld\n", ans);

    return 0;
}