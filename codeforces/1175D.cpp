#include<bits/stdc++.h>
#include<ctime>
using namespace std;
typedef long long ll;
const int maxn = 3e5+7;
const int maxm = 2e6+7;
const ll mod = (1LL<<62);
int n,m,ar[maxn];


ll mid[maxn];
int main()
{
    scanf("%d%d", &n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d", ar+i);
    }
    for(int i=n;i>=1;i--){
        mid[i] = mid[i+1]+ar[i];
    }
    ll ans=mid[1];
    sort(mid+2, mid+n+1);
    for(int i=0;i<m-1;i++){
        ans += mid[n-i];
    }
    printf("%lld\n", ans);
    return 0;
}