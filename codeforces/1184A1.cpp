#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50+7;
const ll mod = 1e9+7;
 
int n,m;
int main()
{
    ll x=0,y=0;
    ll h;
    scanf("%lld", &h);
    for(ll i=1;i*i<=h;i++){
        ll now = h-i*i-i-1;
        if(now>0 && now%(2*i)==0){
            x=i;
            y=now/(2*i);
            break;
        }
        if(now<=0)break;
    }
    if(x==0)printf("NO\n");
    else printf("%lld %lld\n",x,y);
    return 0;
}