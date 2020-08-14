#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int sz = 31;

int n,m,ar[maxn];
map<int,int> ma;
vector<int> xx, yy;
int main()
{
    ll l,r;
    scanf("%lld%lld", &l, &r);
    if(r-l>=2020)printf("0\n");
    else{
        ll ans = 2019;
        for(ll i=l;i<=r;i++){
            for(ll j=i+1;j<=r;j++)ans = min(ans, i*j%2019);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
