#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;
int n,m,k;

ll f[maxn], inv[maxn], sinv[maxn];
ll cc(ll a,ll b){
    if(a<b)return 0;
    if(a==b || b==0)return 1;
    return f[a]*sinv[a-b]%mod*sinv[b]%mod;
}
int main()
{ 
    scanf("%d%d", &n,&k);
    m=n-k;
    f[0] = 1;
    for(int i=1;i<maxn;i++)f[i] = f[i-1]*i%mod;
    inv[0] = inv[1] = 1;
    for(int i=2;i<maxn;i++)inv[i] = inv[mod%i]*(mod-mod/i)%mod;
    sinv[0] = 1;
    for(int i=1;i<maxn;i++)sinv[i] = sinv[i-1]*inv[i]%mod;
    for(int i=1;i<maxn;i++)assert(f[i] * sinv[i] % mod == 1);

    for(int i=1;i<=k;i++){
        printf("%lld\n", cc(m+1, i) * cc(k-1, i-1)%mod);
    }
    



    return 0;
}
