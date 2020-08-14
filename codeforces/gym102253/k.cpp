#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2+7;
const int mod = 1e9+7;
typedef long long ll;

int main()
{
    ll n,m,cas=0;
    while(scanf("%lld%lld", &n, &m)==2){
        ll a,b;
        a = m / (n-1) + 1;
        b = m % (n-1);
        if(b==0){
            a--;
            b=n-1;
        }
        ll ans;
        if(a==1)ans = b;
        else{
            if(b==1)ans = n-(a%2);
            else ans = b-1;
        }
        printf("Case #%lld: %lld\n", ++cas, ans);


    }
    return 0;
}
