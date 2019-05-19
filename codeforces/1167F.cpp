#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;

int n,m;
int ar[maxn];

ll num[maxn<<1], sum[maxn<<1];
map<int,int> ma;
set<int> se;
int ins;
void update1(int x, ll v){
    v %= mod;
    while(x<=ins){
        num[x] = (num[x] + v)%mod;
        x += x&(-x);
    }
}
ll que1(int x){
    ll ans=0;
    while(x>0){
        ans = (ans + num[x])%mod;
        x -= x&(-x);
    }
    return ans;
}
void update2(int x, ll v){
    v %= mod;
    while(x>0){
        sum[x] = (sum[x] + v)%mod;
        x -= x&(-x);
    }
}
ll que2(int x){
    ll ans=0;
    while(x<=ins){
        ans = (ans + sum[x])%mod;
        x += x&(-x);
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d", ar+i);
        se.insert(ar[i]);
    }
    ins=0;
    for(auto x : se){
        ma[x] = ++ins;
    }
    ll ans=0,now=0;
    for(ll i=1;i<=n;i++){
        int in = ma[ar[i]];
        update1(in, i);
        now += que1(in)*ar[i];
        now += que2(in+1);
        update2(in, ar[i]*i);
        now %= mod;
        ans = (ans + now)%mod;
        //cout<<"i, now = "<<i<<" "<<now<<"\n";
    }
    printf("%lld\n", ans);
    return 0;
}