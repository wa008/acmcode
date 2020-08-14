#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;
const ll mod = 1000000000000037;

int n,m,ar[maxn];



int main()
{
    ll a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld\n", c*2 + min(a+b, min(a,b)*2+1));

    return 0;
}