#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+7;
const ll mod = 1e9 + 9;
#define afdafafafdafaf y1;
int ar[maxn], n;

int main()
{
    ll n;
    while(scanf("%lld", &n) != EOF){
        ll ans = n / 3 * 2;
        ans += (n % 3) == 2;
        printf("%lld\n", ans);
    }
    return 0;
}
