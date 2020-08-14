#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;
int ar[maxn];

ll s[maxn];
ll f[maxn],pre[maxn];
ull x = 9223372036854775807;
int main()
{
    ll k,n,m,p;
    while(scanf("%lld%lld%lld%lld",&k,&m,&n,&p)==4){
        for(int i=1;i<=k;i++)scanf("%lld", s+i);
        sort(s+1, s+k+1);
        //for(int i=1;i<=k;i++)cout<<s[i]<<" ";cout<<"\n";
        ll ans=0,lay=0,ins=1;
        f[0]=1;
        for(int i=1;i<=m;i++){
            f[i] = f[i-1]*n%p;
        }
        pre[0]=1;
        for(int i=1;i<=m;i++)pre[i] = (f[i]+pre[i-1])%p;
        for(int i=2;i<=m;i++){
            for(int j=1;j<=f[i-1];j++){
                //cout<<s[ins]<<" "<<pre[m-i]<<"\n";
                ans = (ans + s[ins++]*pre[m-i])%p;
            }
        }
        printf("%lld\n", ans);
    }


    return 0;
}
