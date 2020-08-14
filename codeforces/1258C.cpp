#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
int n,m;
int ar[maxn];
ll s[maxn];
int main()
{
    ll n;
    scanf("%lld", &n);
    ll mx = sqrt(n);
    ll ans = n, a = 1, b = n;
    for(ll i=1;i<=mx;i++){
        if(n % i == 0){
            ll ano = n / i;
            if(__gcd(ano, i) == 1 && ans > max(i, ano)){
                a = i;
                b = ano;
                ans = max(i, ano);
            }
        }
    }
    printf("%lld %lld\n", a, b);
 
    return 0;
}