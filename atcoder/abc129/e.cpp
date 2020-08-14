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
    scanf("%s", ch+1);
    n=strlen(ch+1);
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i] = (f[i-1]*3)%mod;
    }
    ll a=1,ans=0;
    for(int i=1;i<=n;i++){
        if(ch[i]=='1'){
            ans += f[n-i]*a;
            ans %= mod;
        }
        if(ch[i]=='1'){
            a = a*2%mod;
        }
        //cout<<i<<" "<<ans<<" "<<a<<" "<<b<<endl;
    }
    ans = (ans + a)%mod;
    printf("%lld\n", ans);

    return 0;
}