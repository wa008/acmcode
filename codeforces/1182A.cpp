#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;
int n,m,ar[maxn];

char ch[maxn];
ll f[maxn];
int main()
{
    int n;
    ll ans;
    scanf("%d",&n);
    if(n&1)ans=0;
    else{
        ans = (1LL << (n/2));
    }
    printf("%lld\n", ans);

    return 0;
}