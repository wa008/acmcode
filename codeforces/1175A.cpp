#include<bits/stdc++.h>
#include<ctime>
using namespace std;
typedef long long ll;
const int maxn = 3e5+7;
const int maxm = 2e6+7;
const ll mod = (1LL<<62);
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        ll a,b;
        scanf("%lld%lld", &a,&b);
        ll ans=0;
        while(a>0){
            if(a%b==0){
                a/=b;
                ans++;
            }
            else{
                ans += a%b;
                a = a - a%b;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}